export module Hedgehog.Core.Renderer;

import Hedgehog.Core.Window;
export namespace Hedgehog
{
	export namespace Core
	{
		export class IRenderer
		{
		public:
			virtual void Init() = 0;
			virtual void Frame() = 0;
			virtual void Reset() = 0;
		private:
		};
	}
}