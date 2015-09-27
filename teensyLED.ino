/**
 * Teachable Moment via USB Devices
 * Project at secuso/TUD
 * using a teensy microcontroller as a HID
 *
 * This version just opens "site" in all three OS. And determines the 
 * connected OS by checking LED states.
 *
 * Thanks to irongeek, offensive security and
 * security sift for their great work.
 * [irongeek]http://www.irongeek.com/i.php?page=security/programmable-hid-usb-keystroke-dongle
 * [offensive security]https://www.offensive-security.com/offsec/advanced-teensy-penetration-testing-payloads/
 * [security sift]http://www.securitysift.com/fun-with-teensy/
 *
 * (c) 2015 Filip Lueneberg
 * Licensed under GPLv2
 */

/**
* Constants
*/
//change site here
const char *site = "http://www.google.de";



/**
 * Common Functions
 */
//clear all keys
void clearKeys (void) {
  delay(200);
  Keyboard.set_key1(0);
  Keyboard.set_key2(0);
  Keyboard.set_key3(0);
  Keyboard.set_key4(0);
  Keyboard.set_key5(0);
  Keyboard.set_key6(0);
  Keyboard.set_modifier(0);
  Keyboard.send_now();
}
//sends a certain keystroke
void sendKey(uint8_t keyin) {
  Keyboard.set_key1(keyin);
  Keyboard.send_now();
  clearKeys();
  delay(100);
}
//check led keys state
int ledKeys(void) {
  return int(keyboard_leds);
}
//check if numlock is on
boolean isNumLockOn(void) {
  return ((ledKeys() & 1) == 1) ? true : false;
}
//check if scrolllock is on
boolean isScrollLockOn(void) {
  return ((ledKeys() & 4) == 4) ? true : false;
}
//resets locks to off
void resetLock(void) {
  if (isNumLockOn()) {
    sendKey(KEY_NUM_LOCK);
  }
  if (isScrollLockOn()) {
    sendKey(KEY_SCROLL_LOCK);
  }
}
void changeDirectory(char *path, char *directory) {
  Keyboard.print("cd ");
  Keyboard.print(path);
  Keyboard.print(directory);
  sendKey(KEY_ENTER);
}
/**
 * Windows Functions
 */
//opens a command prompt in windows
void win_openRun(void) {
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(100);
  clearKeys();
}
void win_openCmd(void) {
  win_openRun();
  delay(100);
  Keyboard.print("cmd.exe");
  delay(100);
  sendKey(KEY_ENTER);
}
//deletes a file
//currently not used
void win_deleteFile(const char *path, const char *filename) {
  win_openCmd();
  Keyboard.print("del ");
  Keyboard.print(path);
  Keyboard.print(filename);
  sendKey(KEY_ENTER);
  Keyboard.print("exit");
  sendKey(KEY_ENTER);
}
//toggles numlock
void win_toggleLock(void) {
  win_openCmd();
  Keyboard.print("echo Set WshShell = WScript.CreateObject(\"WScript.Shell\"): WshShell.SendKeys \"{NUMLOCK}\" > script.vbs");
  sendKey(KEY_ENTER);
  Keyboard.print("start script.vbs");
  sendKey(KEY_ENTER);
  Keyboard.print("exit");
  sendKey(KEY_ENTER);
}
//opens the default web browser with the constant site
void win_OpenBrowser(void) {
  win_openRun();
  Keyboard.print("﻿cmd /c start ");
  delay(100);
  Keyboard.print(site);
  delay(100);
  sendKey(KEY_ENTER);
}
//script for windows
void winScript(void) {
  win_OpenBrowser();
}

/**
 * Linux Functions
 */
//opens the gnome terminal
void lin_openRun(void) {
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_F2);
  Keyboard.send_now();
  clearKeys();
  delay(100);
}
void lin_openTerminal(void) {
  lin_openRun();
  Keyboard.print("gnome-terminal");
  sendKey(KEY_ENTER);
  delay(400);
}
//toggles scrolllock
void lin_toggleLock(void) {
  lin_openTerminal();
  Keyboard.print("xset led 3");
  delay(100);
  sendKey(KEY_ENTER);
  Keyboard.print("exit");
  delay(100);
  sendKey(KEY_ENTER);
}
//script for gnu/linux
void linScript(void) {
  lin_openTerminal();
  Keyboard.print("xdg-open ");
  Keyboard.print(site);
  sendKey(KEY_ENTER);
}

/**
 * Mac Functions
 *
 * there were issues concerning the led keys
 * with the mac keyboards.
 *
 */
//open spotlight
void mac_spotlight(void) {
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now();
  clearKeys();
  delay(100);
}
//mac script
void macScript(void) {
  mac_spotlight();
  delay(100);
  Keyboard.print("safari");
  delay(100);
  sendKey(KEY_ENTER);
  delay(100);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_T);
  Keyboard.send_now();
  Keyboard.print(site);
  sendKey(KEY_ENTER);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  resetLock();
  win_toggleLock();
  lin_toggleLock();
  if (isNumLockOn()) {
    winScript();
  } else if (isScrollLockOn()) {
    delay(200);
    linScript();
  } else macScript();
}

void loop() {
  // put your main code here, to run repeatedly:

}
