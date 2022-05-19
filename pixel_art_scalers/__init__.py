import _pixel_art_scalers
from PIL import Image

def hq2x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_hq2x_32(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def hq3x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_hq3x_32(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def hq4x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_hq4x_32(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def xbr2x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_xbr_filter_xbr2x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def xbr3x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_xbr_filter_xbr3x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def xbr4x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_xbr_filter_xbr4x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def scalex_2x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_scaler_scalex_2x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def scalex_3x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_scaler_scalex_3x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)

def scalex_4x(src_img : Image) -> Image:
    if src_img.mode != "RGBA":
        src_img = src_img.convert("RGBA")

    dest, dest_width, dest_height = _pixel_art_scalers.py_scaler_scalex_4x(src_img.tobytes(), src_img.width, src_img.height)

    return Image.frombytes("RGBA", (dest_width, dest_height), dest)
