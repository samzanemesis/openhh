#include <sdlxx/core.h>

#include <SDL.h>
#include <SDL_syswm.h>

import Hedgehog.Core.Window;
import Hedgehog.Core.Renderer;
import Hedgehog.Core.RendererBgfx;

export module Hedgehog.Core.Application;

export namespace Hedgehog
{
	export namespace Core
	{
		export class CApplication
		{
		public:
			CApplication();
			~CApplication();

			void Run();

		private:
			void Init();

			bool RunEvents();

			sdlxx::CoreApi* m_pCoreApi;

			CWindow* m_pWindow;
			IRenderer* m_pRenderer;
		};

		CApplication::CApplication()
		{
			Init();
		}

		CApplication::~CApplication()
		{
			if( m_pWindow )
				delete m_pWindow;

			if( m_pCoreApi )
				delete m_pCoreApi;
		}

		void CApplication::Init()
		{
			m_pCoreApi = new sdlxx::CoreApi(sdlxx::CoreApi::Flag::VIDEO);

			m_pWindow = new CWindow();
			m_pRenderer = new CRendererBgfx( m_pWindow );

		}

		void CApplication::Run()
		{
			while ( RunEvents() )
			{
				m_pRenderer->Frame();
			}
		}

		bool CApplication::RunEvents()
		{
			sdlxx::Event e;
			while (sdlxx::Events::Poll(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					return false;
				}

				switch (e.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
					m_pRenderer->Reset();
				}
			}
			return true;
		}
	}
}