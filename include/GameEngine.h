#ifndef GAMEENGINE_H
#define GAMEENGINE_H


class GameEngine
{
    public:
        GameEngine();
        virtual ~GameEngine();
        void Run();
    protected:
    private:
        void GameLoop();
};

#endif // GAMEENGINE_H
