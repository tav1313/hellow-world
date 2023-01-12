CC = gcc-12
CFLAGS = -fPIC
VPATH = str1:build

# Specify paths to headers
INCLUDES += -I/opt/homebrew/Cellar/gtk4/4.8.3/include/gtk-4.0 -I/opt/homebrew/Cellar/pango/1.50.12/include/pango-1.0 \
			-I/opt/homebrew/Cellar/harfbuzz/5.3.1/include/harfbuzz -I/opt/homebrew/Cellar/pango/1.50.12/include/pango-1.0 \
			-I/opt/homebrew/Cellar/fribidi/1.0.12/include/fribidi -I/opt/homebrew/Cellar/harfbuzz/5.3.1/include/harfbuzz \
			-I/opt/homebrew/Cellar/graphite2/1.3.14/include -I/opt/homebrew/Cellar/gdk-pixbuf/2.42.10/include/gdk-pixbuf-2.0 \
			-I/opt/homebrew/Cellar/jpeg-turbo/2.1.4/include -I/opt/homebrew/Cellar/libtiff/4.4.0_1/include \
			-I/opt/homebrew/Cellar/cairo/1.16.0_5/include/cairo -I/opt/homebrew/Cellar/pixman/0.42.2/include/pixman-1 \
			-I/opt/homebrew/Cellar/fontconfig/2.14.1/include -I/opt/homebrew/opt/freetype/include/freetype2 \
			-I/opt/homebrew/Cellar/libpng/1.6.39/include/libpng16 -I/opt/homebrew/Cellar/libxcb/1.15/include \
			-I/opt/homebrew/Cellar/libxrender/0.9.11/include -I/opt/homebrew/Cellar/libxext/1.3.5/include \
			-I/opt/homebrew/Cellar/libx11/1.8.2/include -I/opt/homebrew/Cellar/libxcb/1.15/include \
			-I/opt/homebrew/Cellar/libxau/1.0.11/include -I/opt/homebrew/Cellar/libxdmcp/1.1.4/include \
			-I/opt/homebrew/Cellar/graphene/1.10.8/include/graphene-1.0 \
			-I/opt/homebrew/Cellar/graphene/1.10.8/lib/graphene-1.0/include -I/opt/homebrew/Cellar/glib/2.74.4/include \
			-I/opt/homebrew/Cellar/glib/2.74.4/include/glib-2.0 -I/opt/homebrew/Cellar/glib/2.74.4/lib/glib-2.0/include \
			-I/opt/homebrew/opt/gettext/include -I/opt/homebrew/Cellar/pcre2/10.42/include \
			-I/opt/homebrew/Cellar/xorgproto/2022.2/include \
			-I/Library/Developer/CommandLineTools/SDKs/MacOSX13.sdk/usr/include/ffi

INC1 = $(shell pkg-config --cflags gtk4)

# Specify paths to the libraries
LDFLAGS  += -L/opt/homebrew/Cellar/gtk4/4.8.3/lib -L/opt/homebrew/Cellar/pango/1.50.12/lib \
			-L/opt/homebrew/Cellar/harfbuzz/5.3.1/lib -L/opt/homebrew/Cellar/gdk-pixbuf/2.42.10/lib \
			-L/opt/homebrew/Cellar/cairo/1.16.0_5/lib -L/opt/homebrew/Cellar/graphene/1.10.8/lib \
			-L/opt/homebrew/Cellar/glib/2.74.4/lib -L/opt/homebrew/opt/gettext/lib

# Specify the link libraries
LLIBS += -lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 \
		-lgio-2.0 -lgobject-2.0 -lglib-2.0 -lintl

build/bin/main : main.o rs1.o
#	mkdir build/bin
	$(CC) -g $(LDFLAGS) $(LLIBS) $? -o $@

build/main.o : main.c
#	mkdir build
	$(CC) -g -c -pthread $(CFLAGS) $(INC1) $? -o $@

build/rs1.o : rs1.c
	$(CC) -g -c -pthread $(CFLAGS) $(INC1) $? -o $@

.PHONY = clean
clean:
	rm -rvf build

.PHONE = run
run: main
	./build/bin/main