// Function to set the alarm time
// Parameters:
// Message received from telegram
// Returns:
// none
void setAlarm(string message)
{

  string Tmsg = message.substring(0, 1)
  hourAlarm = message.substring(3, 4).toInt()
  minAlarm  = message.substring(5, 6).toInt()

  switch (Tmsg)

  { //                                            0123456
    case 'A1':                            			// we are setting Alarm 1 from Telegram msg: "A1:0059"
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm1", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm1", minAlarm);   // Write the minute value to the preferences
      preferences.putBool("Alarm1", true);   		// Enable A1
      preferences.end();                           	// Close pereferences
      break;
    case 'A2':                            			// we are setting Alarm 2 from Telegram msg: "A2:2359"
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm2", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm2", minAlarm);   // Write the minute value to the preferences
      preferences.putBool("Alarm2", true);   		// Enable A2
      preferences.end();                            // Close pereferences
      break;
    case 'A3':                            			// we are setting Alarm 3 from Telegram msg: "A3:2359"
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm3", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm3", minAlarm);   // Write the minute value to the preferences
      preferences.putBool("Alarm3", true);   		// Enable A3
      preferences.end();                           	// Close pereferences
      break;
    case 'A4':                            			// we are setting Alarm 4 from Telegram msg: "A4:2359"
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm4", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm4", minAlarm);   // Write the minute value to the preferences
      preferences.putBool("Alarm4", true);   		// Enable A4
      preferences.end();                            // Close pereferences
      break;
    case 'A5':                            			// we are setting Alarm 5 from Telegram msg: "A5:2359"
      preferences.begin("alarms", false);      		// Open preferences
      preferences.putUInt("hourAlarm5", hourAlarm); // Write the hour value to the preferences
      preferences.putUInt("minAlarm5", minAlarm);   // Write the minute value to the preferences
      preferences.putBool("Alarm5", true);   		// Enable A5
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
  preferences.putBool("Alarm1", false);   		// disable A1
  preferences.putBool("Alarm2", false);   		// disable A2
  preferences.putBool("Alarm3", false);   		// disable A3
  preferences.putBool("Alarm4", false);   		// disable A4
  preferences.putBool("Alarm5", false);   		// disable A5
  preferences.end();                            // Close pereferences
}



// Function to get all enabled alarms settings from non-volatile memory
// Parameters:
// None
// Returns:
// None
void getAlarmSettings()
{
  AlrArray[ 5 ][ 3 ] = { { false, 0, 0 }, { false, 0, 0 }, { false, 0, 0 }, { false, 0, 0 }, { false, 0, 0 } };

  preferences.begin("alarms", false);          // Open preferences
  
  if (preferences.getBool("Alarm1"))
  {
    AlrArray[0][0] = true;
    AlrArray[0][1] = preferences.getUInt("hourAlarm1", 0);
    AlrArray[0][2] = preferences.getUInt("minAlarm1", 0);
  }
  if (preferences.getBool("Alarm2")) {
    AlrArray[1][0] = true;
    AlrArray[1][1] = preferences.getUInt("hourAlarm2", 0);
    AlrArray[1][2] = preferences.getUInt("minAlarm2", 0); 
  }
  if (preferences.getBool("Alarm3")) {
    AlrArray[2][0] = true;
    AlrArray[2][1] = preferences.getUInt("hourAlarm3", 0);
    AlrArray[2][2] = preferences.getUInt("minAlarm3", 0);
  }
  if (preferences.getBool("Alarm4")) {
    AlrArray[3][0] = true;
    AlrArray[3][1] = preferences.getUInt("hourAlarm4", 0);
    AlrArray[3][2] = preferences.getUInt("minAlarm4", 0);
  }
  if (preferences.getBool("Alarm5")) {
    AlrArray[4][0] = true;
    AlrArray[4][1] = preferences.getUInt("hourAlarm5", 0);
    AlrArray[4][2] = preferences.getUInt("minAlarm5", 0);
  }
  preferences.end();                               // Close preferences

}



// Function to check the time against the alarms time
// Parameters:
// none
// Returns:
// true if they match, false if they don't match
bool timeCheck()

int hourAlarm, minAlarm;

{
  // loop through array's rows
  for ( int i = 0; i < 5; ++i ) {
    if (AlrArray[ i ][ 0 ] == true {
    hourAlarm = AlrArray[i] [1]
    minAlarm  = AlrArray[i] [2]
      // If the hours and minutes match...
      if (rtcTime.hour() == hourAlarm && rtcTime.minute() == minAlarm)
      {
        return true;  // ...return true
      }
    }
  }
  // If not...
  return false; // ...return false
}
