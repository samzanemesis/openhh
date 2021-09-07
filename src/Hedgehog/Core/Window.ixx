#include <sdlxx/core.h>
#include <SDL.h>
#include <SDL_syswm.h>

export module Hedgehog.Core.Window;

export namespace Hedgehog
{
	export namespace Core
	{
		export class CWindow
		{
		public:
			CWindow();
			~CWindow();

			sdlxx::Window* GetWindow() { return pWindow; }
			void* GetHwnd();

			
			struct WindowSize_t
			{
				int nWidth;
				int nHeight;
			};

			inline WindowSize_t GetWindowSize();

		private:
			sdlxx::Window* pWindow;
			SDL_Window* _window;
		};
		
		CWindow::CWindow()
		{
			_window = SDL_CreateWindow("Ayy",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				640, 480, SDL_WINDOW_RESIZABLE);
			pWindow = new sdlxx::Window(_window);
		}

		CWindow::~CWindow()
		{
			delete pWindow;
		}

		void* CWindow::GetHwnd()
		{
			SDL_SysWMinfo wmi;
			SDL_VERSION(&wmi.version);
			if (!SDL_GetWindowWMInfo(_window, &wmi))
				return nullptr;

			#if _WIN32
				return wmi.info.win.window;
			#elif __APPLE__
				return wmi.info.cocoa.window;
			#elif __linux__
				pd.ndt = wmi.info.x11.display;
				return (void*)(uintptr_t)wmi.info.x11.window;
			#else
				#error Please return the correct window handle for a new platform
			#endif
		}

		CWindow::WindowSize_t CWindow::GetWindowSize()
		{
			return { GetWindow()->GetSize().width, GetWindow()->GetSize().height };
		}
	}
}