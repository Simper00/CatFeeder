// Function to set the alarm time
// Parameters:
// Message received from telegram
// Returns:
// none
void setAlarm(string message)
{
	
	string Tmsg = message.substring(0,1)
	
    switch (Tmsg)

    {                                      			//                                            0123456
    case 'A1':                            			// we are setting Alarm 1 from Telegram msg: "A1:0059"
      hourAlarm1 = message.substring(3, 4).toInt()
	  minAlarm1  = message.substring(5, 6).toInt()
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm1", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm1", minAlarm);   // Write the minute value to the preferences
	  preferences.putBool("Alarm1", TRUE);   		// Enable A1
      preferences.end();                           	// Close pereferences
      break;
    case 'A2':                            			// we are setting Alarm 2 from Telegram msg: "A2:2359"
      hourAlarm1 = message.substring(3, 4).toInt()
	  minAlarm1  = message.substring(5, 6).toInt()
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm2", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm2", minAlarm);   // Write the minute value to the preferences
	  preferences.putBool("Alarm2", TRUE);   		// Enable A2
      preferences.end();                           // Close pereferences
      break;    
     case 'A3':                            			// we are setting Alarm 3 from Telegram msg: "A3:2359"
      hourAlarm3 = message.substring(3, 4).toInt()
	  minAlarm3  = message.substring(5, 6).toInt()
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm3", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm3", minAlarm);   // Write the minute value to the preferences
	  preferences.putBool("Alarm3", TRUE);   		// Enable A3
      preferences.end();                           	// Close pereferences
      break;
    case 'A4':                            			// we are setting Alarm 4 from Telegram msg: "A4:2359"
      hourAlarm4 = message.substring(3, 4).toInt()
	  minAlarm4  = message.substring(5, 6).toInt()
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm4", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm4", minAlarm);   // Write the minute value to the preferences
	  preferences.putBool("Alarm4", TRUE);   		// Enable A4
      preferences.end();                            // Close pereferences
      break;   
	case 'A5':                            			// we are setting Alarm 5 from Telegram msg: "A5:2359"
      hourAlarm5 = message.substring(3, 4).toInt()
	  minAlarm5  = message.substring(5, 6).toInt()
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm5", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm5", minAlarm);   // Write the minute value to the preferences
	  preferences.putBool("Alarm5", TRUE);   		// Enable A5
      preferences.end();                            // Close pereferences
      break;    
    }
  }
  
// Function to disable the alarms
// Parameters:
// none
// Returns:
// none
void disableAlarm()
{
// we are disabling all the alarms when receiving Telegram msg: "Azzera"

      preferences.begin("alarms", false);      		// Open preferences
	  preferences.putBool("Alarm1", FALSE);   		// disable A1
	  preferences.putBool("Alarm2", FALSE);   		// disable A2
	  preferences.putBool("Alarm3", FALSE);   		// disable A3
	  preferences.putBool("Alarm4", FALSE);   		// disable A4
	  preferences.putBool("Alarm5", FALSE);   		// disable A5
      preferences.end();                            // Close pereferences
  }
 
  

// Function to get the Alarm settings from non-volatile memory
// Parameters:
// None
// Returns:
// None
void getAlarmSettings()
{
  preferences.begin("alarms", false);          // Open preferences
  Alarm1 = preferences.getBool("Alarm1");    // Get alarm1 status
  Alarm2 = preferences.getBool("Alarm2");    // Get alarm2 status
  Alarm3 = preferences.getBool("Alarm3");    // Get alarm3 status
  Alarm4 = preferences.getBool("Alarm4");    // Get alarm4 status
  Alarm5 = preferences.getBool("Alarm5");    // Get alarm5 status
  
 if(Alarm1)
 { hourAlarm1 = preferences.getUInt("hourAlarm1", 0); // Get alarm hour and place in a global variable
  minAlarm1 = preferences.getUInt("minAlarm1", 0);   // Get alarm minute and place in a global variable
 }
 if (Alarm2){
  hourAlarm2 = preferences.getUInt("hourAlarm2", 0); // Get alarm hour and place in a global variable
  minAlarm2 = preferences.getUInt("minAlarm2", 0);   // Get alarm minute and place in a global variable
 }
 if (Alarm3){
  hourAlarm3 = preferences.getUInt("hourAlarm3", 0); // Get alarm hour and place in a global variable
  minAlarm3 = preferences.getUInt("minAlarm3", 0);   // Get alarm minute and place in a global variable
 }
 if (Alarm4){
  hourAlarm4 = preferences.getUInt("hourAlarm4", 0); // Get alarm hour and place in a global variable
  minAlarm4 = preferences.getUInt("minAlarm4", 0);   // Get alarm minute and place in a global variable
 }
 if (Alarm5){
  hourAlarm5 = preferences.getUInt("hourAlarm5", 0); // Get alarm hour and place in a global variable
  minAlarm5 = preferences.getUInt("minAlarm5", 0);   // Get alarm minute and place in a global variable
 }
  preferences.end();                               // Close preferences  
}



// Function to check the time against the alarm time
// Parameters:
// none
// Returns:
// true if they match, false if they don't match
bool timeCheck()
{

  if (rtcTime.hour() == hourAlarm && rtcTime.minute() == minAlarm)
  {              // If the hours and minutes match...
    return true; // ...return true
  }
  else
  {               // If not...
    return false; // ...return false
  }
}
