#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"

import Hedgehog.Core.Renderer;
import Hedgehog.Core.Window;

export module Hedgehog.Core.RendererBgfx;

export namespace Hedgehog
{
	export namespace Core
	{
		export class CRendererBgfx : public IRenderer
		{
		public:
			CRendererBgfx(CWindow* window);
			~CRendererBgfx();

			void Init() override;
			void Frame() override;
			void Reset() override;
		private:
			void HookWindow();

			CWindow* m_pWindow;
		};

		CRendererBgfx::CRendererBgfx(CWindow* window)
		{
			m_pWindow = window;
			Init();
		}

		CRendererBgfx::~CRendererBgfx()
		{
			bgfx::shutdown();
		}

		void CRendererBgfx::Init()
		{
			HookWindow();
		}

		void CRendererBgfx::Reset()
		{

			CWindow::WindowSize_t nWindowSize = m_pWindow->GetWindowSize();
			bgfx::reset(nWindowSize.nWidth, nWindowSize.nHeight);
		}
		void CRendererBgfx::HookWindow()
		{
            bgfx::PlatformData pd{};
            pd.nwh = m_pWindow->GetHwnd();

			CWindow::WindowSize_t nWindowSize = m_pWindow->GetWindowSize();

            bgfx::Init bgfx_init;
            bgfx_init.type = bgfx::RendererType::Count; // auto choose renderer
            bgfx_init.resolution.width = nWindowSize.nWidth;
            bgfx_init.resolution.height = nWindowSize.nHeight;
            bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
            bgfx_init.platformData = pd;
            bgfx::init(bgfx_init);

            bgfx::setViewClear(
                0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
            bgfx::setViewRect(0, 0, 0, nWindowSize.nWidth, nWindowSize.nHeight);
		}

		void CRendererBgfx::Frame()
		{
			bgfx::setDebug(true ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
			bgfx::frame();
		}
	}
}