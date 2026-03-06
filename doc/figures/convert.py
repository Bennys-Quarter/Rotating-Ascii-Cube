from PIL import Image, ImageDraw, ImageFont

# Read text

line_height = 18
width = 800
offset = 100
nr_f = 64

font = ImageFont.truetype("DejaVuSansMono.ttf", 16)

for i in range(nr_f):
    with open(f"{i}.txt", "r") as f:
        lines = [line.rstrip("\n") for line in f]

        rows = len(lines)
        cols = max(len(line.rstrip("\n")) for line in lines)
        
        height = line_height * len(lines)

        # Create image
    
        img = Image.new("RGB", (height, width), "black")
        draw = ImageDraw.Draw(img)
            
        for j, line in enumerate(lines):
            draw.text((0, j * line_height+offset), line, fill="white", font=font)
        
        # Save PNG
        img.save(f"o_{i}.png")

images = []

for i in range(nr_f):
    with open(f"o_{i}.png", "rb") as f:
        img = Image.open(f)
        images.append(img.copy())
    
images[0].save(
    "animation.gif",
    save_all=True,
    append_images=images[1:],
    duration=100,
    loop=0
)
        