// 게임 루프
int main() {
    int fps = 60;
    double frameTime = 1000.0 / fps;

    // 전역 변수로 스크린 버퍼 선언
    char screenBuffer[(WIDTH + 1) * HEIGHT];
    int screenWidth = WIDTH;
    int screenHeight = HEIGHT;

    GameObject_Line LineObj[3];

    // 게임 초기화
    Initialize(LineObj, 3);

    Elf2DInitScreen();
    Elf2DClearScreen(screenBuffer, screenWidth, screenHeight);
    Elf2DDrawBuffer(screenBuffer);

    ElfTimeInitialize();

    int isGameRunning = 1;
    while (isGameRunning) {

        int gameEvent = Input();

        //입력 계산
        if (gameEvent == 99)
        {
            isGameRunning = 0;
        }

        // 게임 업데이트
        Update(LineObj, 3, gameEvent);

        // 스크린버퍼에 게임 렌더링
        Render(LineObj, 3, screenBuffer, screenWidth, screenHeight);

        // 화면 그리기
        Elf2DDrawBuffer(screenBuffer);

        ElfTimeCalculateDeltaTime();
        Elf2DSleep(frameTime - ElfTimeGetDeltaTime());
    }

    return 0;
}