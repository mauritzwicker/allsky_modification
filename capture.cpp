// TO BE USED WITH: capture.cpp in allsky repository
// NOT A WORKING CODE
// COMPILE WITH MAKEFILE IN ALLSKY REPO

// ####################### LIBRARIES  #######################
// those in the repo
#include <stdlib.h>
#include <signal.h>
#include <fstream>
#include <ftypeinfo>

// ####################### FOR SAVING THE XML  #######################
void *SaveImgThd(void *para)
{
    while (bSaveRun)
    {
        pthread_mutex_lock(&mtx_SaveImg);
        pthread_cond_wait(&cond_SatrtSave, &mtx_SaveImg)
        bSavingImg = true;
        if (pRgb.data)
        {
            cv::FileStorage fp("/path/to/allsky/repo/data_raw_live.xml", cv::FileStorage::WRITE);
            fp << "pRgb" << pRgb;
            fp.release();

            imwrite(fileName, pRgb, compression_parameters);
            if (dayOrNight == "NIGHT")
            {
                //to not archive the xml data leave this first part out
                system("scripts/saveXMLData.sh &");
                system("scripts/saveImageNight.sh &");
            }
            else
            {
                //to not archive the xml data leave this first part out
                system("scripts/saveXMLData.sh &");
                system("scripts/saveImageDay.sh &");
            }
        }
        bSavingImg = false;
        pthread_mutex_unlock(&mtx_SaveImg);
    }

    printf("save thread over\n");
    return(void *)0;
}


// to save the xml data
if (!bSaveRun)
{
    bSaveRun = true;
    if (pthread_create(&thdSave, 0, SaveImgThd, 0) != 0)
    {
        bSaveRun = false;
    }
}




// ####################### FOR SAVING THE TXT  #######################

void writeInfoRawLog(float temp_xml, int gain_xml, int bs_xml, int gam_xml, int wbred_xml, int wbblue_xml, int bin_xml, char const *lat_xml, char const *long_xml, std::string daynight_xml, int expt_xml)
{
    std::ofstream outfile:
    outfile.open("xml_log.txt", std::ios_base::trunc);
    outfile << "temp " << temp_xml;
    outfile << "\n";
    outfile << "gain " << gain_xml;
    outfile << "\n";
    outfile << "brightness " << bs_xml;
    outfile << "\n";
    outfile << "wb red " << wbred_xml;
    outfile << "\n";
    outfile << "wb blue " << wbblue_xml;
    outfile << "\n";
    outfile << "binning " << bin_xml;
    outfile << "\n";
    outfile << "latitude " << lat_xml;
    outfile << "\n";
    outfile << "longitude " << long_xml;
    outfile << "\n";
    outfile << "day-or-night " << daynight_xml;
    outfile << "\n";
    outfile << "t_exp " << expt_xml;
    outfile << "\n";
}

// to save the txt data
writeInfoRawLog((float)ltemp / 10.0, asiGain, asiBrightness, asiGamma, asiWBR, asiWBB, bin, latitude, longitude, lastDayOrNight, (float)autoExp);

