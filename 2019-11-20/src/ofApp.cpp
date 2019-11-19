#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	camera.setDistance(400);
	ofSetCircleResolution(3);

//	image.loadImage("metal.jpg");
//	doesDrawImg = false;
	doesShowHelp  = true;
	fbo.allocate(ofGetWidth(), ofGetHeight());

	glitch.setup(&fbo);

}

//--------------------------------------------------------------
void ofApp::update(){
	fbo.begin();
	ofClear(0, 0, 0,255);
//	if (!doesDrawImg){
		camera.begin();

		for (int i = 0;i < 100;i++){
			if		(i % 5 == 0)ofSetColor(50 , 255, 100);
			else if (i % 9 == 0)ofSetColor(255, 50, 100);
			else				ofSetColor(255, 255, 255);

			ofPushMatrix();
			ofRotateDeg(ofGetFrameNum(), 1.0, 1.0, 1.0);
			ofDrawCircle(0, 0, ofRandom(100));
			ofPopMatrix();
		}
		
		camera.end();
//	}else{
//		ofSetColor(255);
//		image.draw(0, 0);
//	}
	fbo.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
	glitch.generateFx();
    
	ofSetColor(255);
	fbo.draw(0, 0);

	string info = "";
	info += "1 - 0 : Apply glitch effects.\n";
	info += "q - u : Apply color remap effects.\n";
	info += "L key : Switch 3Dview / 2DImage.\n";
	info += "H key : Hide or show this information.";

	if (doesShowHelp){
		ofSetColor(0, 200);
		ofRotateDeg(25, 17, 320, 60);
		ofSetColor(255);
		ofDrawBitmapString(info, 30,30);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') glitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
	if (key == '2') glitch.setFx(OFXPOSTGLITCH_GLOW			, true);
	if (key == '3') glitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
	if (key == '4') glitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
	if (key == '5') glitch.setFx(OFXPOSTGLITCH_TWIST			, true);
	if (key == '6') glitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
	if (key == '7') glitch.setFx(OFXPOSTGLITCH_NOISE			, true);
	if (key == '8') glitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
	if (key == '9') glitch.setFx(OFXPOSTGLITCH_SWELL			, true);
	if (key == '0') glitch.setFx(OFXPOSTGLITCH_INVERT			, true);

	if (key == 'q') glitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
	if (key == 'w') glitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
	if (key == 'e') glitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
	if (key == 'r') glitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
	if (key == 't') glitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
	if (key == 'y') glitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
	if (key == 'u') glitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);

//	if (key == 'l') doesDrawImg ^= true;
	if (key == 'h') doesShowHelp ^= true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == '1') glitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
	if (key == '2') glitch.setFx(OFXPOSTGLITCH_GLOW			, false);
	if (key == '3') glitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
	if (key == '4') glitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
	if (key == '5') glitch.setFx(OFXPOSTGLITCH_TWIST			, false);
	if (key == '6') glitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
	if (key == '7') glitch.setFx(OFXPOSTGLITCH_NOISE			, false);
	if (key == '8') glitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
	if (key == '9') glitch.setFx(OFXPOSTGLITCH_SWELL			, false);
	if (key == '0') glitch.setFx(OFXPOSTGLITCH_INVERT			, false);

	if (key == 'q') glitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
	if (key == 'w') glitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
	if (key == 'e') glitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
	if (key == 'r') glitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
	if (key == 't') glitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
	if (key == 'y') glitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
	if (key == 'u') glitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
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
