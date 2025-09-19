# Piece 用 makefile

# 拡張子の定義

.SUFFIXES: .c .s .h .o .srf
#.SUFFIXES: .c .s .h .o .srf

# 生成コマンド・オプションのマクロ

CC = pcc33
CFLAGS = -c -g -gp=0x0 -near -O2 -Wall -DFASTCODE -I.
AS = pcc33
ASFLAGS = -c -g -gp=0x0 -near
LD = pcc33
LDFLAGS = -g -ls -lm +bssblock FRAM {mus.o} +addr 0x1000 {FRAM}

# 生成規則

.c.o:
	$(CC) $(CFLAGS) $<

.s.o:
	$(AS) $(ASFLAGS) $<

# 構成ファイル・生成ファイルのマクロ

PRGNAME = sample
LIBNAME = muslib
OBJS =	app.o testseq.o instdef.o
LIBOBJS = mus.o musfast.o seq.o exp12.o wavetable.o
FILENAME = music
CAPTION = MusicSample
ICON = music.pid

INSTOBJS =\
	wave\i_BD909.o\
	wave\i_CYMBD.o\
	wave\i_HANDCLAP.o\
	wave\i_HC909.o\
	wave\i_HO909.o\
	wave\i_SD909.o\
	wave\i_SDGATE.o\
	wave\i_TOMH1.o\
	wave\i_TOML1.o\
	wave\i_TOMM1.o\

#$(PRGNAME).srf : $(OBJS) $(LIBOBJS)
#	$(LD) $(LDFLAGS) -e$(PRGNAME).srf $(OBJS) $(LIBOBJS) $(INSTOBJS)

lib: $(LIBNAME).lib

$(LIBNAME).lib : $(LIBOBJS)
	lib33 -a $(LIBNAME).lib $(LIBOBJS)
	lib33 -a $(LIBNAME).lib $(INSTOBJS)

# 依存関係
#
testseq.o : testseq.dat
app.o : muslib.h
mus.o : muslib.h musdef.h
seq.o : musdef.h
instdef.o : musdef.h
wavetable.o : musdef.h


# フラッシュ書き込みイメージ生成
pex : $(PRGNAME).srf
	ppack -e $(PRGNAME).srf -o$(FILENAME).pex -n$(CAPTION) -i$(ICON)


# クリーンアップ
clean:
	del $(PRGNAME).srf $(PRGNAME).pex $(PRGNAME).sym $(PRGNAME).map *.o\
	$(LIBNAME).lib

# テスト実行
run: $(PRGNAME).srf
	cmd /c run

# インストール
install:
	copy $(LIBNAME).lib ..\..\lib
	copy muslib.h ..\..\include
	copy musdef.h ..\..\include
