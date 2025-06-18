#include "core/Application.h"

Application* globalApp = nullptr;

int main() {
    Application app;
    globalApp = &app;
    app.run();
    return 0;
}