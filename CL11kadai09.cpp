#define _CRT_SECURE_NO_WARNINGS
//------------------------------------------//
//		kadai09 �s�J�^��					//
//------------------------------------------//
#include <stdio.h>
#include <string.h>
//------------�v���g�^�C�v�錾--------------//
void waitkey();
bool length_check(char* name);
void ng_check(char* name, char ng[][9], int ngflag[2], int n);
//-----------------�I���-------------------//

//-----------------main�֐�-----------------//
int main(void) {

	bool lenflag = false;
	int ngflag[2] = { 0,0 };//1�ځF1�Ȃ�true0�Ȃ�false 2�ځF������������ng���[�h�̏ꏊ

	char name[1024];//���O
	//�ŏ����֎~�P��̎�ނ̐��A�������ꂼ��̕������A���l�̃C���[�W���ƍŏ����c�Ŏ�����
	//10�P��ŉ��s���Ă��܂�
	char ng[][9] = {
		"����",   "�܂�",   "���񂿂�", "�܂�܂�", "����",   "�����",   "�܂�",   "�܂��",   "�G�b�`",   "�A��",
		"�������", "�܁���",   "�܂�k",    "�}�\�R",   "�܂��",   "���@�M�i", "����k",    "�`���|",   "�y�j�X",   "penis",
		"���񂽂�", "���_",     "�u�N",     "�{�b�L",   "���q",     "�ː�",     "�U�[����", "�Z�b�N�X", "SEX",      "sex",
		"PENIS",    "S��X",     "s��x",     "�̈�",     "����",     "�A�i��",   "���Ȃ�",   "anus",     "�����ς�", "oppai",
		"�p���c",   "�p���e�B", "�p��t",    "����",     "������",   "�`�N�r",   "�r�[�`�N", "����",     "�I�i�j",   "�I�i�k",
		"��������", "��������", "�N���j",   "�t�F��",   "�܂񂮂�", "�p�C�Y��", "����",     "�ӂ�����", "�Ӂ[����", "�\�[�v",
		"�f���w��", "��",       "��s",     "�ق�����", "����",     "�ǂ��Ă�", "�ǂ��ā[", "�ǁ[�ā[", "�ǁ[�Ă�", "����",
		"����",     "���܂�", "�����}��", "����",     "�o�C�u",   "���[�^�[", "�p�C�p��", "���o��",   "���c��",   "�Ȃ�����",
		"�X�J�g��", "�����Ƃ�", "��",       "����",   "�E���R",   "�p�R�p�R", "�ς��ς�", "�z��",     "homo",     "�ς��ς�",
		"�p�C�p�C", "�m�[�u��", "��R�L",   "�Ă���",   "�e�R�L",   "��}��",   "�Ă܂�",   "�e�}��",   "����",     "�w�}��",
		"��т܂�", "���r�}��", "�`���R",   "�}���R",   "�`���`��", "�}���}��", "�C�����E", "���C�v",   "�Ƃ�",     "������",
		"�L���C",   "���߂�",   "���߂�",   "�ϑ�",     "�n��",     "�΁[��",   "�΂�",     "�o�J",     "baka",     "fuck",
		"�t�@�b�N", "�u�X",     "�C�Ⴂ",   "��n�O",   "��������", "�L�`�K�C", "�u�^",     "�����΂�", "bitch",    "�r�b�`",
		"�т���",   "��",       "����",     "����",     "shine",    "��",       "�E",       "���낷",   "�R���X",   "�V�l",
		"���낹",   "�R���Z",   "��H",     "�΂΂�",   "�΂΂�",   "�o�A�A",   "�o�o�@",   "BBA",      "����",     "��",
		"�N�Y",     "�喃",     "����",     "��������", "���t",     "���t",     "��������", "����ς�", "����",     "�����",
		"�`���|",   "�ǂ���",   "�y��",     "�Ђɂ�",   "�т���",   "�ǂ���",   "������",   "������", "�؂ɂ�",   "���Ƃ�",
		"������", "���`���R", "�I�`���R", "���܂�", "���}���R", "�I�}���R", "���Ƃ�",   "��������", "�߂���",   "��点��",
		"���Ȃ���", "��肱��", "�����R��", "�`����",   "�}����",   "�f���L�`", "�ł񂫂�",	"�f���g",   "�ł�g",   "�ӂ���",
		"������",   "�A�N��",   "��������", "�A�k�X",   "�C���N��", "���񂩂�", "�����",   "��������", "���炷��", "���킼��",
		"��������", "������",   "���ނ�",   "���ނ�",   "���ނ���", "���ނ�",   "���ꂭ��", "��������", "������",   "�������",
		"���Ȃ���", "�����ρ[", "���΂܂�", "����",     "���񂵂�", "���Ƃ�",   "���傱��", "���[��",   "�����܂�", "�����܂�",
		"�����",   "P",        "�����ӂ�", "������",   "48��",     "��������"
	};

	int word_num = sizeof(ng) / 9;

	do {
		if (lenflag == true) {
			printf("�����������B�I�I�I\n");
		}
		if (ngflag[0] == 1) {
			printf("%s���g���Ȃ�Ă����Ȃ�����\n", ng[ngflag[1]]);
		}

		printf("���O����͂��Ă�\n");
		scanf("%s", name);

		lenflag = length_check(name);
		ng_check(name, ng, ngflag, word_num);

	} while (ngflag[0] == 1 || lenflag == true);

	printf("�E��%s�̓G�b�`���Ď��ɂ܂���\n", name);
	waitkey();
	return 0;
}
//-----------------�I���-------------------//

//----------------waitkey�֐�---------------//
void waitkey() {
	rewind(stdin);
	getchar();
}
//-------------waitkey�֐������------------//

//-------------length_check�֐�-------------//
bool length_check(char* name) {
	if (strlen(name) > 9) {
		return true;
	}
	return false;
}
//----------length_check�֐������----------//

//---------------ng_check�֐�---------------//
void ng_check(char* name, char ng[][9], int ngflag[2], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (strstr(name, ng[i]) != NULL) {
			ngflag[0] = 1;
			ngflag[1] = i;
			return;
		}
	}
	ngflag[0] = 0;
}

//���������Ȃ�J��Ԃ�
//OK�Ȃ當����������������������\��