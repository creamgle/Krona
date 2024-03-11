#pragma once

/**
    Application is the starting point to all projects

    example (MyApp is custom class that extends application)
    ----------
    Application* myApp = new MyApp();
    myApp->Run();
    delete myApp;
*/

#include "Krona/Core/Window.h"
#include "KronaCore.h"

namespace Krona {

    class KRAPI Application {
        public:
            virtual ~Application() = default;

            bool Run();

            Window& GetWindow() const { return *mWindow; }

        protected:
            /**
                Application->Create() is called from Application->Run(),
                use this to setup things such as scenes, loading user files
                and other various things

                **the application closes if Create() returns false
            */
            virtual bool Create() = 0;
            
            /**
                Application->Update() is called once every frame
            */
            virtual void Update() { }
    
        private:
            Scope<Window> mWindow;
    };

}
