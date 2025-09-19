
CC = pcc33
CFLAGS = -g -gp=0x0 -near -O2  -Wall
AS = pcc33
ASFLAGS = -g -gp=0x0 -near
LD = pcc33
LDFLAGS = -g 


fpkplay.srf: fpkplay.o decode.o fpk.o
	$(LD) $(CFLAGS) -e$@ fpkplay.o decode.o fpk.o music\\muslib.lib

fpkplay.o: fpkplay.c fpack.h lzss.h
decode.o: decode.c lzss.h
fpk.o: fpk.c fpk.h

pex: fpkplay.pex
fpkplay.pex: fpkplay.srf
	ppack -e -v -n"FPACK player" $< -o$@

run: fpkplay.srf
	isd r"$<"
copy: fpkplay.pex
	isd =w"$<"
#	isd =w"fpkplay.fpk"


%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o fpkplay.srf
