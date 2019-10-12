#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCurveResolution(25);

    gui.setup();
    gui.add(firstX.setup("firstX", 1, 1, 3000));
    gui.add(firstY.setup("firstY", 1, 1, 3000));
    gui.add(secondX.setup("secondX", 1, 1, 3000));
    gui.add(secondY.setup("secondY", 1, 1, 3000));
}

//--------------------------------------------------------------
void ofApp::update(){
    xNoise += 0.1;
    yNoise += 0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int y = ofGetHeight()/2;
    int x = ofGetWidth()/2;
    
    ofNoFill();
    ofSetColor(255);
    
    ofTranslate(x, y);
    for(int i = 0; i < 10000; i++){
        ofRotateDeg(15);
//        ofDrawBezier(ofRandom(0,2*x),ofRandom(0,2*y),
//                     i,i,
//                     i,i,
//                     ofRandom(0,2*x),ofRandom(0,2*y));
        ofDrawBezier(0,0,
                     i,i,
                     i,i,
                     4*x,0);

//
//        ofRotateDeg(15);
//        ofDrawBezier(2*x,2*y,
//                     i,i,
//                     i,i,
//                     0,2*y);
    }

//    gui.draw();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
