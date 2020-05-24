#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			//PlayerIdle,
			//PlayerAttack,
			//PlayerDead,
			Tileset,
			BG,
			Particles,
			Ground,
			Cow,
			Blacksmith,
			Shopkeeper,
			BloodiedHammer,
			Panacea,
			GreenVial,
			Bell,
			Towncrier,
			PlagueDoctor,
			BGObject1,
			BGObject2,
			BGObject3,
			BGObject4,
			BGObject5,
			BGObject6,
			BGObject7,
			Count,
		};
	}

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:			return "knight_animations.png";
		//case eTexture::PlayerIdle:		return "knight_idle.png";
		//case eTexture::PlayerAttack:	return "knight_attack.png";
		//case eTexture::PlayerDead:		return "knight_death.png";
		case eTexture::Tileset:			return "tileset.png";
		case eTexture::BG:				return "starry_background.png";
		case eTexture::Particles:		return "particles.png";
		case eTexture::Ground:			return "ground.png";
		case eTexture::Cow:				return "cow_animation.png";
		case eTexture::Blacksmith:		return "blacksmith.png";
		case eTexture::Shopkeeper:		return "shopkeeper.png";
		case eTexture::Towncrier:		return "town_crier.png";
		case eTexture::PlagueDoctor:	return "doctor.png";
		case eTexture::BloodiedHammer:  return "bloodied_hammer.png";
		case eTexture::Panacea:		    return "panacea.png";
		case eTexture::GreenVial:		return "green_vial.png";
		case eTexture::Bell:			return "bell.png";
		case eTexture::BGObject1:	return "background1.png";
		case eTexture::BGObject2:	return "background2.png";
		case eTexture::BGObject3:	return "background3.png";
		case eTexture::BGObject4:	return "background4.png";
		case eTexture::BGObject5:	return "background5.png";
		case eTexture::BGObject6:	return "background6.png";
		case eTexture::BGObject7:	return "background7.png";
		default:						return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture)
		{
		case  GameEngine::eTexture::Player:  return sf::Vector2f(420.0f, 341.0f);
		//case  GameEngine::eTexture::PlayerIdle:  return sf::Vector2f(252.f, 280.f);
		//case  GameEngine::eTexture::PlayerAttack:  return sf::Vector2f(272.f, 344.f);
		//case  GameEngine::eTexture::PlayerDead:  return sf::Vector2f(341.f, 288.f);
		case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::BG:				return sf::Vector2f(1920.f, 1200.f);
		case  GameEngine::eTexture::Particles: return sf::Vector2f(31.f, 32.f);
		case  GameEngine::eTexture::Ground: return sf::Vector2f(480.f, 100.f);
		case  GameEngine::eTexture::Blacksmith: return sf::Vector2f(225.0f, 225.0f);
		case  GameEngine::eTexture::Shopkeeper: return sf::Vector2f(225.0f, 225.0f);
		case  GameEngine::eTexture::Towncrier: return sf::Vector2f(225.0f, 225.0f);
		case  GameEngine::eTexture::PlagueDoctor: return sf::Vector2f(225.0f, 225.0f);
		case  GameEngine::eTexture::BloodiedHammer: return sf::Vector2f(32.0f, 32.0f);
		case  GameEngine::eTexture::Panacea:		return sf::Vector2f(32.0f, 32.0f);
		case  GameEngine::eTexture::GreenVial:		return sf::Vector2f(32.0f, 32.0f);
		case  GameEngine::eTexture::Bell:			return sf::Vector2f(32.0f, 32.0f);
		case  GameEngine::eTexture::Cow:			return sf::Vector2f(476.f, 304.f);
		default:									return sf::Vector2f(-1.f, -1.f);
		}
	}
}

