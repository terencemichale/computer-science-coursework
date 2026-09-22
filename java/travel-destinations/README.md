# Travel Destination List

A Java Swing coursework application showing five travel destinations, descriptions, and resized images in a custom list renderer.

## Run

Requires a JDK and a graphical desktop. From this directory:

```bash
mkdir build
javac -d build src/TopFiveDestinationList.java
```

PowerShell: `java -cp "build;src" TopFiveDestinationList`

macOS/Linux: `java -cp "build:src" TopFiveDestinationList`

The `src` classpath entry makes `/resources/...` image paths available. Compiled classes and JAR files are intentionally excluded.

## Contribution and credits

The source describes my changes to an existing list-view exercise: destination selections and descriptions, image resizing, and readability adjustments. It is presented as a customized coursework exercise, not a wholly original UI framework.

Photographer credits retained from the supplied source/filenames: Ulziibayar Badamdorj (Andaman Coast), Alain Bonnardeaux (Patagonia), Gabriela Ceja (Hokkaido), Christian Garcia (Costa Rica), and K. Mitch Hodge (Canary Islands), via Unsplash. Images retain their original rights; they are not covered by a new repository-wide license.

The fifth destination label was completed during portfolio cleanup. See verification notes for build/runtime status.
