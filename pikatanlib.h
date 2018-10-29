//--------------------------------------//
//	pikatanlib.h						//
//	�s�J�^��							//
//--------------------------------------//

//�J�[�\���̐���
//�R���\�[���̃J�[�\���c���̖��̒ʂ�R���\�[���Ō��݂̈ʒu�������J�[�\��
//out_cursor�֐��Ain_cursor�֐��ł̃J�[�\���c�ǂ��̕������I�����Ă��邩�������T�O

#pragma once

//���͂����L�[�̒l
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

/*�S��ʃN���A*/
void clear();

/*�R���\�[���̃J�[�\�����\���ɂ���*/
void disable_cursor();

/*�R���\�[���̃J�[�\����\��������*/
void enable_cursor();

/*���L�[�ő��삵�����ɃJ�[�\������O�ꂽ��������Â�����*/
void out_cursor();

/*������̃J�[�\���̈ʒu�����߂� �߂�l�F�X�V�����J�[�\���̈ʒu ��1�����F���͂������� ��2�����F�ύX�O�̃J�[�\���̈ʒu ��3�����F�J�[�\���̐�-1 ��4�����F��̐�*/
int get_cursor(int c, int cursor, int cmax, int row);

/*�������͂���֐�*/
int get_key();

/*���L�[�ő��삵�����ɃJ�[�\��������������𖾂邭����*/
void in_cursor();

/*���͑҂�*/
void wait_key();
