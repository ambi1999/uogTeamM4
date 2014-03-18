import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.TrayItem;
import org.eclipse.ui.forms.widgets.FormToolkit;
import org.eclipse.ui.forms.widgets.Section;


public class Main {

	protected Shell shlColourPicker;
	private Text text;
	private Text text_1;
	private Text text_2;
	private Text txtCalibrating;
	private final FormToolkit formToolkit = new FormToolkit(Display.getDefault());

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Main window = new Main();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shlColourPicker.open();
		shlColourPicker.layout();
		while (!shlColourPicker.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shlColourPicker = new Shell();
		shlColourPicker.setSize(285, 172);
		shlColourPicker.setText("#Scan\r\n");
		
		Label label = new Label(shlColourPicker, SWT.NONE);
		label.setText("Red");
		label.setBounds(10, 13, 45, 15);
		
		Label lblGreen = new Label(shlColourPicker, SWT.NONE);
		lblGreen.setBounds(10, 44, 45, 15);
		lblGreen.setText("Green");
		
		Label lblBlue = new Label(shlColourPicker, SWT.NONE);
		lblBlue.setBounds(10, 76, 39, 15);
		lblBlue.setText("Blue");
		
		text = new Text(shlColourPicker, SWT.BORDER);
		text.setFont(SWTResourceManager.getFont("Segoe UI", 9, SWT.BOLD));
		text.setForeground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		text.setBackground(SWTResourceManager.getColor(SWT.COLOR_RED));
		text.setText("0");
		text.setBounds(75, 10, 76, 21);
		
		text_1 = new Text(shlColourPicker, SWT.BORDER);
		text_1.setFont(SWTResourceManager.getFont("Segoe UI", 9, SWT.BOLD));
		text_1.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));
		text_1.setForeground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		text_1.setText("0");
		text_1.setBounds(75, 44, 76, 21);
		
		text_2 = new Text(shlColourPicker, SWT.BORDER);
		text_2.setFont(SWTResourceManager.getFont("Segoe UI", 9, SWT.BOLD));
		text_2.setForeground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		text_2.setBackground(SWTResourceManager.getColor(SWT.COLOR_BLUE));
		text_2.setText("0");
		text_2.setBounds(75, 76, 76, 21);
		
		txtCalibrating = new Text(shlColourPicker, SWT.BORDER);
		txtCalibrating.setTouchEnabled(true);
		txtCalibrating.setFont(SWTResourceManager.getFont("Arial", 8, SWT.NORMAL));
		txtCalibrating.setBackground(SWTResourceManager.getColor(SWT.COLOR_GRAY));
		txtCalibrating.setText("Calibrating...");
		txtCalibrating.setBounds(192, 107, 71, 21);
		
		Canvas canvas = new Canvas(shlColourPicker, SWT.NONE);
		canvas.setBackground(SWTResourceManager.getColor(SWT.COLOR_RED));
		canvas.setBounds(169, 10, 94, 87);
		
		Label label_1 = new Label(shlColourPicker, SWT.SEPARATOR | SWT.VERTICAL);
		label_1.setBounds(63, 13, 2, 84);

	}
}
