import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class TopFiveDestinationList {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
            	TopDestinationListFrame topDestinationListFrame = new TopDestinationListFrame();
                topDestinationListFrame.setTitle("Top 5 Destination List");
                topDestinationListFrame.setVisible(true);
            }
        });
    }
}


class TopDestinationListFrame extends JFrame {
    private DefaultListModel<TextAndIcon> listModel;

    public TopDestinationListFrame() {
        super("Top Five Destination List");

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(900, 750);

        listModel = new DefaultListModel<>();


        //Make updates to your top 5 list below. Import the new image files to resources directory.
        //Terence Michale: 	Added five January travel destinations with images and descriptions
        //					Refactored icon to resize using resizeImage() before passing the icon to build the list 
        
        // Destination images sourced from Unsplash.
        // Individual photographer credits are provided above each image.
        
        // Image credit: Ulziibayar Badamdorj via Unsplash
        addDestinationNameAndPicture("1. Andaman Coast, Thailand - Tropical beaches and clear skies make January ideal for island hopping",resizeImage("/resources/andaman-coast-thailand-ulziibayar-badamdorj-unsplash.jpg"));
        
        // Image credit: Alain Bonnardeaux via Unsplash
        addDestinationNameAndPicture("2. Patagonia, Argentina - Summer weather makes January ideal for exploring glaciers and mountain trails", resizeImage("/resources/patagonia-argentina-alain-bonnardeaux-unsplash.jpg"));
        
        // Image credit: Gabriela Ceja via Unsplash
        addDestinationNameAndPicture("3. Hokkaido, Japan - January brings light powdery snow ideal for skiing and winter activities", resizeImage("/resources/hokkaido-japan-gabriela-ceja-unsplash.jpg"));
        
        // Image credit: Christian Garcia via Unsplash
        addDestinationNameAndPicture("4. La Fortuna & Arenal, Costa Rica - January is ideal for rainforest hikes, volcanoes, and wildlife", resizeImage("/resources/costa-rica-christian-garcia-unsplash.jpg"));
        
        // Image credit: K. Mitch Hodge via Unsplash
        addDestinationNameAndPicture("5. Canary Islands, Spain - Warm winter weather makes January ideal for beaches and outdoor activities", resizeImage("/resources/canary-islands-spain-k-mitch-hodge-unsplash.jpg"));
        
        JList<TextAndIcon> list = new JList<>(listModel);
        JScrollPane scrollPane = new JScrollPane(list);

        TextAndIconListCellRenderer renderer = new TextAndIconListCellRenderer(2);

        // Customize the ListView for readability.
        list.setBackground(Color.WHITE);
        list.setSelectionForeground(Color.WHITE);
        list.setFont(new Font("Arial", Font.PLAIN, 14));
        list.setCellRenderer(renderer);

        JLabel nameLabel = new JLabel("Developer: Terence Michale");
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));
        nameLabel.setHorizontalAlignment(JLabel.CENTER);
        
        getContentPane().add(nameLabel, BorderLayout.NORTH);
        getContentPane().add(scrollPane, BorderLayout.CENTER);
    }

    // Resize destination images so each ListView item displays consistently.
    private ImageIcon resizeImage(String imagePath) {
    	ImageIcon original = new ImageIcon(getClass().getResource(imagePath));
    	Image scaledImage = original.getImage().getScaledInstance(
    	        180, 120, Image.SCALE_SMOOTH
    	    );
    	
    	return new ImageIcon(scaledImage);
    }
    private void addDestinationNameAndPicture(String text, Icon icon) {
        TextAndIcon tai = new TextAndIcon(text, icon);
        listModel.addElement(tai);
    }
}


class TextAndIcon {
    private String text;
    private Icon icon;

    public TextAndIcon(String text, Icon icon) {
        this.text = text;
        this.icon = icon;
    }

    public String getText() {
        return text;
    }

    public Icon getIcon() {
        return icon;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setIcon(Icon icon) {
        this.icon = icon;
    }
}


class TextAndIconListCellRenderer extends JLabel implements ListCellRenderer<TextAndIcon> {
    private static final Border NO_FOCUS_BORDER = new EmptyBorder(1, 1, 1, 1);

    private Border insideBorder;

    public TextAndIconListCellRenderer() {
        this(0, 0, 0, 0);
    }

    public TextAndIconListCellRenderer(int padding) {
        this(padding, padding, padding, padding);
    }

    public TextAndIconListCellRenderer(int topPadding, int rightPadding, int bottomPadding, int leftPadding) {
        insideBorder = BorderFactory.createEmptyBorder(topPadding, leftPadding, bottomPadding, rightPadding);
        setOpaque(true);
    }

    public Component getListCellRendererComponent(JList<? extends TextAndIcon> list, TextAndIcon value,
    int index, boolean isSelected, boolean hasFocus) {
        // The object from the combo box model MUST be a TextAndIcon.
        TextAndIcon tai = value;

        // Sets text and icon on 'this' JLabel.
        setText(tai.getText());
        setIcon(tai.getIcon());

        if (isSelected) {
            setBackground(Color.GRAY);
            setForeground(list.getSelectionForeground());
        } else {
            setBackground(Color.PINK);
            setForeground(list.getForeground());
        }

        Border outsideBorder;

        if (hasFocus) {
            outsideBorder = UIManager.getBorder("List.focusCellHighlightBorder");
        } else {
            outsideBorder = NO_FOCUS_BORDER;
        }

        // Customize the ListView font and colors for readability.
        setBorder(BorderFactory.createCompoundBorder(outsideBorder, insideBorder));
        setComponentOrientation(list.getComponentOrientation());
        setEnabled(list.isEnabled());
        setFont(list.getFont());
        
        return this;
    }

    // The following methods are overridden to be empty for performance
    // reasons. If you want to understand better why, please read:
    //
    // http://java.sun.com/javase/6/docs/api/javax/swing/DefaultListCellRenderer.html#override

    public void validate() {}
    public void invalidate() {}
    public void repaint() {}
    public void revalidate() {}
    public void repaint(long tm, int x, int y, int width, int height) {}
    public void repaint(Rectangle r) {}
}
