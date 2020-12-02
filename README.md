# allsky_modification
Code to use in @thomasjacquin repo "allsky" as modifications to save 16-bit pixel data, and modified for web.

## THIS IS NOT A WORKING DIRECTORY << it is simply a collection of code that can be added into allsky-repo for doing the following ##
- saving the 16-bit image data as pixel-counts in xml data files.
- saving parameters of exposure in a txt file
- using a bash script to archive this information

Final:
- saving the 16-bit live image data in an xml file (overwriting old files)
- saving the live exposure parameters in a txt file
- bash script to run the evaluation of xml and parameters data, saving into a txt file
- html implementation of the evaluated (also saved txt file)


FOR SAVING XML DATA CONTINUOUSLY

capture.cpp
- code to add into capture.cpp of allsky repository
- need to: sudo make capture
- output is: live xml data file and live txt data file

saveXMLData.sh
- is located in /scripts/ directory
- is called by capture.cpp to archive the live xml data file
- this moves the live xml data file into a directory with its name and changes the filename





FOR SAVING AND ANALYZING ONLY LIVE XML DATA

run_evaluation.sh
- this is to run the evaluation_files.py
(maybe just include the py running in ./allsky.sh)

evaluation_files.py
- this is to evaluate our xml data (for star count)
- this is then saved with the info from live txt data file into a txt file
- the output text file is the one for the webpage

implement_web.html
- this is the web implementation for waltz webpage
- this takes the txt final txt files and shows them on the page

