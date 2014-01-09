#include <Dxlib.h>
#include <memory>
#include "global.h"
#include "ConstParam.h"
#include "GameManager.h"
#pragma warning(disable:4996)

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ) {
	SetGraphMode(ConstParam::SCREEN_WIDTH, ConstParam::SCREEN_HEIGHT, 32);//��ʃT�C�Y�C��
	//if (MessageBox(NULL,"�t���X�N���[���ŋN�����܂����H","�N���I�v�V����",MB_YESNO) == IDYES) {
	//	ChangeWindowMode(FALSE);
	//} else {
	//	ChangeWindowMode(TRUE);
	//}

	SetOutApplicationLogValidFlag(FALSE);
	SetMainWindowText("SINRYAKU");
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//�t�H���g�ǂݍ���
	//const char* font_path = "dat/BMmini.TTF";
	//AddFontResourceEx(font_path, FR_PRIVATE, NULL);
	//ChangeFont("BM mini", DX_CHARSET_DEFAULT);//�������ꂵ���g��Ȃ�
	//SetFontSize(18);

	//�f�o�O�p�ɃR���\�[���o���Ă��
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	auto gm = std::make_shared<GameManager>();

	while (ProcessMessage() == 0) {
		InputUpdate();

		gm->Move();
		
		ClearDrawScreen();
		gm->Draw();
		ScreenFlip();
		if (GetKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	//RemoveFontResourceEx(font_path, FR_PRIVATE, NULL);
	FreeConsole();
	DxLib_End();
	return 0;
}
