#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\Util\CameraManager.h"
#include "Game\GameEntities\PlayerEntity.h"
#include "Game\GameEntities\ObstacleEntity.h"
#include "Game\GameEntities\GroundEntity.h"
#include "Game\GameEntities\AnimatedObjectEntity.h"
#include "GameEntities/SubEntities/Blacksmith.h"
#include "GameEntities/SubEntities/Shopkeeper.h"
#include "GameEntities/SubEntities/Towncrier.h"
#include "GameEntities/SubEntities/Plaguedoctor.h"
#include "GameEntities/SubEntities/Collectibles/BloodiedHammer.h"
#include "GameEntities/SubEntities/Collectibles/Panacea.h"
#include "GameEntities/SubEntities/Collectibles/GreenVial.h"
#include "GameEntities/SubEntities/Collectibles/Bell.h"
#include "Game\GameEntities\BackgroundEntity.h"

using namespace Game;

GameBoard::GameBoard()
	: m_lastObstacleSpawnTimer(0.f)
	, m_isGameOver(false)
	, m_player(nullptr)
	, m_backGround(nullptr)
{
	m_player = new PlayerEntity();
	
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(0.f, 0.f));	
	m_player->SetSize(sf::Vector2f(200.f, 250.f));
	
	CreateBackGround();
	CreateGround();
	//Debug
	for (int a = 0; a < 3; ++a)
	{
		//SpawnNewRandomObstacles();
	}

	SpawnRandomObjects();
	//Cow
	m_cow = new AnimatedObjectEntity(GameEngine::EAnimationId::CowAnim, GameEngine::eTexture::Cow);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_cow);
	m_cow->SetPos(sf::Vector2f(-400.0f, -150.0f));
	m_cow->SetSize(sf::Vector2f(155.0f, 100.f));

	//BlackSmith
	m_blacksmith = new Blacksmith();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_blacksmith);
	m_blacksmith->SetPos(sf::Vector2f(100.0f, 220.0f));
	m_blacksmith->SetSize(sf::Vector2f(180.0f, 180.0f));

	//ShopKeeper
	m_shopkeeper = new Shopkeeper();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_shopkeeper);
	m_shopkeeper->SetPos(sf::Vector2f(600.0f, 200.0f));
	m_shopkeeper->SetSize(sf::Vector2f(180.0f, 180.0f));

	//Towncrier
	m_towncrier = new Towncrier();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_towncrier);
	m_towncrier->SetPos(sf::Vector2f(1200.0f, 200.0f));
	m_towncrier->SetSize(sf::Vector2f(180.0f, 180.0f));

	//Plaguedoctor
	m_plaguedoctor = new Plaguedoctor();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_plaguedoctor);
	m_plaguedoctor->SetPos(sf::Vector2f(1600.0f, 200.0f));
	m_plaguedoctor->SetSize(sf::Vector2f(180.0f, 180.0f));

	//Collectibles

	bloodHammer = new BloodiedHammer();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bloodHammer);
	bloodHammer->SetPos(sf::Vector2f(800.0f, 200.0f));
	bloodHammer->SetSize(sf::Vector2f(50.0f, 50.0f));
	
	panacea = new Panacea();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(panacea);
	panacea->SetPos(sf::Vector2f(1800.0f, 200.0f));
	panacea->SetSize(sf::Vector2f(50.0f, 50.0f));
	
	greenVial = new GreenVial();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(greenVial);
	greenVial->SetPos(sf::Vector2f(2000.0f, 200.0f));
	greenVial->SetSize(sf::Vector2f(50.0f, 50.0f));
	
	bell = new Bell();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bell);
	bell->SetPos(sf::Vector2f(2200.0f, 200.0f));
	bell->SetSize(sf::Vector2f(50.0f, 50.0f));

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!m_isGameOver)
	{
		m_lastObstacleSpawnTimer -= dt;
		if (m_lastObstacleSpawnTimer <= 0.f)
		{
			//SpawnNewRandomObstacles();
//			SpawnNewRandomTiledObstacles();
		}

		//UpdateObstacles(dt);
		UpdateBackGround();
		//UpdateGround();
		UpdatePlayerDying();
	}		
	else
	{
		m_player->Death();
	}
}


void GameBoard::UpdateObstacles(float dt)
{
	static float obstacleSpeed = 100.f;
	
	for (std::vector<GameEngine::Entity*>::iterator it = m_obstacles.begin(); it != m_obstacles.end();)
	{
		GameEngine::Entity* obstacle = (*it);
		sf::Vector2f currPos = obstacle->GetPos();
		currPos.x -= obstacleSpeed * dt;
		obstacle->SetPos(currPos);
		//If we are to remove ourselves
		if (currPos.x < -50.f)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(obstacle);
			it = m_obstacles.erase(it);
		}
		else
		{
			it++;
		}
	}
}


void GameBoard::UpdatePlayerDying()
{	
	if (!m_player->isDead)
	{
		return;
	}
	m_isGameOver = true;
}


void GameBoard::CreateGround()
{
	float x_pos0 = -1000.f;
	for (int i = 0; i < 30; i++)
	{
		float x_delta = 480 * float(i);
		GroundEntity* groundEntity = new GroundEntity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(groundEntity);
		groundEntity->SetPos(sf::Vector2f(x_pos0 + x_delta, 310.f));
		groundEntity->SetSize(sf::Vector2f(480.f, 100.f));
	}
}


void GameBoard::SpawnNewRandomObstacles()
{
	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 50.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 20.f;
	static float maxObstacleYPos = 450.f;
	
	static float minObstacleHeight = 50.f;
	static float maxObstacleHeight = 170.f;
	static float minObstacleWidth = 20.f;
	static float maxObstacleWidth = 40.f;

	sf::Vector2f pos = sf::Vector2f(RandomFloatRange(minObstacleXPos, maxObstacleXPos), RandomFloatRange(minObstacleYPos, maxObstacleYPos));
	sf::Vector2f size = sf::Vector2f(RandomFloatRange(minObstacleWidth, maxObstacleWidth), RandomFloatRange(minObstacleHeight, maxObstacleHeight));

	SpawnNewObstacle(pos, size);

	m_lastObstacleSpawnTimer = RandomFloatRange(minNextSpawnTime, maxNextSpawnTime);
}


void GameBoard::SpawnNewRandomTiledObstacles()
{
	static int minObstacleCount = 2;
	static int maxObstacleCount = 7;

	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 350.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 20.f;
	static float maxObstacleYPos = 450.f;

	sf::Vector2f pos = sf::Vector2f(RandomFloatRange(minObstacleXPos, maxObstacleXPos), RandomFloatRange(minObstacleYPos, maxObstacleYPos));	
	sf::Vector2f size = sf::Vector2f(32.f, 32.f);

	int obstacleCount = (int)RandomFloatRange((float)minObstacleCount, (float)maxObstacleCount);
	for (int a = 0; a < obstacleCount; ++a)
	{
		SpawnNewObstacle(pos, size);
		pos.y += size.y;
	}

	m_lastObstacleSpawnTimer = RandomFloatRange(minNextSpawnTime, maxNextSpawnTime);
}


void GameBoard::SpawnNewObstacle(const sf::Vector2f& pos, const sf::Vector2f& size)
{
	ObstacleEntity* obstacle = new ObstacleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);
	obstacle->SetPos(pos);
	obstacle->SetSize(sf::Vector2f(size.x, size.y));

	m_obstacles.push_back(obstacle);
}


void GameBoard::SpawnRandomObjects()
{
	
}


void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(bgEntity->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(0.f, 0.f));
	bgEntity->SetSize(sf::Vector2f(1280.f, 720.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;

	CreateBackGroundObjects();
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || !m_player)
		return;

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;

	m_backGround->SetPos(sf::Vector2f(m_player->GetPos().x, 0.f));
}

void GameBoard::CreateBackGroundObjects()
{
	BackgroundEntity* bgEntity = new BackgroundEntity();
	m_backgroundObjects = bgEntity->renderObjects();
}