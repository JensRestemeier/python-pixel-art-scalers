from pixel_art_scalers import hq2x, hq3x, hq4x, xbr2x, xbr3x, xbr4x, scalex_2x, scalex_3x, scalex_4x
from PIL import Image

src_image = Image.open("test.png")

dst_image = hq2x(src_image)
dst_image.save("test_hq2x.png")

dst_image = hq3x(src_image)
dst_image.save("test_hq3x.png")

dst_image = hq4x(src_image)
dst_image.save("test_hq4x.png")

dst_image = xbr2x(src_image)
dst_image.save("test_xbr2x.png")

dst_image = xbr3x(src_image)
dst_image.save("test_xbr3x.png")

dst_image = xbr4x(src_image)
dst_image.save("test_xbr4x.png")

dst_image = scalex_2x(src_image)
dst_image.save("test_scalex_2x.png")

dst_image = scalex_3x(src_image)
dst_image.save("test_scalex_3x.png")

dst_image = scalex_4x(src_image)
dst_image.save("test_scalex_4x.png")
