//
//  ofkUDPjpegSender.h
//  imageLoaderExample
//
//  Created by Shunichi Kasahara on 11/3/12.
//
//

#ifndef imageLoaderExample_ofkUDPjpegSender_h
#define imageLoaderExample_ofkUDPjpegSender_h

#include "ofxNetwork.h"
#include "ofMain.h"

class ofkUDPjpegSender
{
public:
    ofkUDPjpegSender(void);
    
    bool init(string targetIP, int port, int BufferSize = 22518);
    bool setBufferSize(int BufferSize);
    
    /*
     OF_IMAGE_QUALITY_BEST,
     OF_IMAGE_QUALITY_HIGH,
     OF_IMAGE_QUALITY_MEDIUM,
     OF_IMAGE_QUALITY_LOW,
     OF_IMAGE_QUALITY_WORST
     */
    void setjpegQuality(ofImageQualityType q);
    void setEnableBroadCast(bool isEnableBroadCast);
    bool sendImage(ofPixels &pix);
    
    unsigned long getProcessTime();
    int getSendingDataSize(){return sendDataSize;}
    string getSendIPAdress();
    
private:
    ofxUDPManager udpConnect;
    bool isInitlized;
    ofImageQualityType mQuality;
    ofBuffer jpegVideoBuffer;
    
    int sendDataSize;
    unsigned long s_measureStart;
    unsigned long s_measureEnd;

    
};

#endif
