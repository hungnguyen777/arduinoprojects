#include <EEPROM.h>

int typebutton = 9;
int generatebutton = 8;
int passwordlength = 8;

char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//This contains all the list of characters you can use in the passwords that will be generated

void setup()
{
  pinMode(typebutton, INPUT_PULLUP);
  pinMode(generatebutton, INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
  if (digitalRead(typebutton) == LOW)
  {
    typePassword();
    }
  if (digitalRead(generateButton == LOW)
  {
    generatePassword();
  }
  delay(300);
}

int i;

void typepassword()
{
  for(i = 0; i < passwordlength; i++)
  {
    Keyboard.write(EEPROM.read(i));
  }
  Keyboard.write('\n');
}

void generatePassword()
{
  randomSeed(millis() * analogRead(A0));
  for(i = 0; i < passwordlength; i++)
  {
    EEPROM.write(i, randomLetter());
  }
}

char.randomLetter()
{
  int n = strlen(letters);
  int i = random(n);
  return letters[i];
}
