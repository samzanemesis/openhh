import Hedgehog.Core.Application;
int main(int argc, char** argv)
{
    try
    {
        Hedgehog::Core::CApplication game{};
        game.Run();
    }
    catch (int& e) 
    {
      //  Log::Error(e.what());
    }

    return 0;
}