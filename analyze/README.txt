/*
 *	analyze.cpp
 *  Ikani Samani
 *  Program 3
 *  CS 3370
 *  
 *  No codes were copied in the creation of this file except those allowed by the instructor and or provided
 *  in the instructions for program 4.
 *
 *  Parameter: a *.ini file passed through commandline that should include the following information:
 *  vt = int to check for a rise over three consecutive points that is greater than this parameter
 *  width = parameter to check the width of the pulses
 *  pulse_delta : The between pulses to look for piggybacks
 *  below_drop_ration: int, the number of values less than drop ratio to check against
 *  drop_ratio: double, a number less than 1.
 *
 *  This program is designed to gather all .dat file within the same directory and create a single file to
 *  reference the file names, then process the data to find pulses within the given data.
 *  The file names is return along with the found pulses, the width for those pulse are given
 *  in the linve proceeding it.
 *