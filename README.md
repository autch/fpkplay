# fpkplay

P/ECE �W�������h���C�o�� pmd �t�@�C�������@�ōĐ����܂��Bpmd �t�@�C���ٍ͐� [fpack](https://github.com/autch/funpack) �ł܂Ƃ߂Ĉ��k���� fpk �t�@�C���Ƃ��Ĉ����܂��B

## �C���X�g�[��

`fpkplay.pex` �� `fpkplay.fpk` �t�@�C���� P/ECE ���@�ɓ]�����A���j���[���� `FPACK Player` ���N�����Ă��������B

### `fpkplay.fpk` �̍���

[fpack](https://github.com/autch/funpack) ����肵�Apmd �t�@�C�����܂Ƃ߂��f�B���N�g�����ňȉ��̂悤�ɂ��č쐬���܂��B

```shell-session 
> fpack -e fpkpack.fpk *.pmd
```

fpkplay �ɗ^����ɂ� `-e` �I�v�V�������K�{�ł��B���̃I�v�V������ pmd �t�@�C�������k���܂��B

## ����

�N���ł���� fpk �t�@�C�����̍ŏ��̃t�@�C�����Đ����Ă���͂��ł��B

`seek:` �̍s�͕����L�[���E�Ŏ��ɍĐ�����t�@�C����I�����܂��BA�{�^���ł��̃t�@�C�����Đ����܂��B

`playing:` �̍s�͌��ݍĐ����̃t�@�C�����ł��B

���̎��̍s�ɂ͍Đ����̃t�@�C���̃^�C�g�� (`#Title`) ���A����ɂ��̉��ɂ̓^�C�g���Q (`#Title2`) ��񂪕\������܂��B

* �����L�[���E
  * ���ɍĐ�����t�@�C����I�ԁB`seek:` �s�̃t�@�C�������ω�����
* A�{�^��
  * `seek:` �s�őI�񂾃t�@�C�����Đ�����B�^�C�g�������ς��B
* B�{�^��
  * �Đ����~����B�\���� `seek:` �s�����ɂȂ�B
* START�{�^��
  * ��ʕ\�����~����B������xSTART�{�^���������ƌ��ɖ߂�B
  * �t���ւ̃f�[�^�]�����~�܂邽�߁A�ߓd�ƃI�[�f�B�I�o�͂ɏ��m�C�Y�̍팸�ɂȂ邩������Ȃ��B
* START+SELECT ������
  * �I�����ă��j���[�ɖ߂�B��L�\����~���ɂ��L���B

## �r���h����

1. P/ECE �J�����ւ̃p�X��ʂ��AGNU make �� `rm` ���g����悤�ɂ��Ă����܂��B
1. music/wave �� `mk.bat` �����s���A�h�������F���r���h���Ă����܂�
1. music/ �� `make` ���Amuslib ���r���h���܂��B
1. �Ō�Ƀg�b�v���x���f�B���N�g���� `make pex` ����ƁA `fpkplay.pex` ���ł��܂��B

## muslib �ւ̊g��

�ȉ��̓_�� P/ECE �J�����Y�t�� muslib ����ύX����Ă��܂��B

* �Đ��J�n���̃v�`�m�C�Y�΍�
  * `music/mus.c`
* �G���x���[�v�A�r�u���[�g�A�f�`���[���͖���Đ��O�ɏ���������
  * `music/seq.c`
* �h�������F�����̃m�C�Y�폜
  * `music/wave/i_CYMBD.c`, `i_TOMH1.c`, `i_TOMM1.c`
* �p�[�g���g���Ή��A26�p�[�g�܂�
  * `music/musdef.h`

## ���C�Z���X

�\�[�X�f�B���N�g���̂����A`music/` �ȉ��� P/ECE �J�����Y�t�� muslib �ɗR������R�[�h�ł���A�O���̒ʂ�C������Ă��܂��B���̃f�B���N�g���ɂ��Ă� P/ECE �����T�C�g�� [�t���\�[�X�����ɂ����v���O�����̍Ĕz�z�̈����ɂ���](https://aquaplus.jp/piece/intr.html) �i�y�[�W�����j�ɏ]���܂��B

�g�b�v���x���f�B���N�g���̃t�@�C���� Autch �����������̂ł����ACC0 �Ƃ��܂��B

fpkplay by Autch is marked CC0 1.0. To view a copy of this mark, visit https://creativecommons.org/publicdomain/zero/1.0/
