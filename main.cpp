#include <windows.h>

// Processes messages sent to the window
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_DESTROY) {
        // Window is closed. Post WM_QUIT which will break the message loop
        PostQuitMessage(0);
    }

    // Unhandled messages are sent to the default handler
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CreateEdgeWindow(HINSTANCE hInstance, int x, int y, int width, int height) {
    HWND hwnd = CreateWindowEx(
        WS_EX_TOPMOST | WS_EX_TOOLWINDOW, // On top and exclude from taskbar
        "STATIC", NULL, WS_POPUP, // Simple non-interactive window
        x, y, width, height,
        NULL, NULL, hInstance, NULL // Set parent window. Misc non-important stuff
    );
    ShowWindow(hwnd, SW_SHOW);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    const int WINDOW_THICKNESS = 1;

    CreateEdgeWindow(hInstance, 0, 0, screenWidth, WINDOW_THICKNESS);
    CreateEdgeWindow(hInstance, 0, screenHeight - WINDOW_THICKNESS, screenWidth, WINDOW_THICKNESS);
    CreateEdgeWindow(hInstance, 0, 0, WINDOW_THICKNESS, screenHeight);
    CreateEdgeWindow(hInstance, screenWidth - WINDOW_THICKNESS, 0, WINDOW_THICKNESS, screenHeight);

    // Handle the application's message queue. All I know I use it for is to show the default cursor when hovering over the windows
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
