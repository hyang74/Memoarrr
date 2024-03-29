//
//  Card.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "utils.hpp"
using namespace std;


class Card{
    friend class CardDeck;
    FaceAnimal cardAnimal;
    FaceBackground cardColor;
    Letter let;
    Number num;
    bool faceUp = false;
    int nRows = 3;
    
    Card(FaceAnimal animal, FaceBackground background): cardAnimal(animal), cardColor(background){};
    
public:
    bool topAvailable=true;
    bool bottomAvailable=true;
    bool rightAvailable=true;
    bool leftAvailable=true;
    
    void setIndex(Letter l, Number n){
        changeAvailabilityLetter(l);
        changeAvailabilityNumber(n);
        let=l;
        num=n;
    }
    
    Letter getLetter() const {return let;}
    Number getNumber() const {return num;}
    std::string getPositionString();
    
    int getAnimal() const {return (int)cardAnimal;}
    std::string getAnimalStr();
    int getColor() const {return (int)cardColor;}
    std::string getColorStr();
    
    bool isFaceUp(){return faceUp;}
    void turnFace(bool trueForUp);
    
    Card(const Card&) = delete;
    Card& operator= ( const Card & ) = delete;
    int getNRows() {return nRows;}
    std::string operator()(int i) {
            if(!faceUp){
                return " zzz";
            }
            else{
                if(i==1){
                    return (" "+getColorStr()+getAnimalStr()+getColorStr());
                }
                else{
                    return (" "+(getColorStr()+getColorStr()+getColorStr()));
                }
            }
    }
    
    void changeAvailabilityLetter(Letter l){
        if(l==Letter::A){
            topAvailable=false;
        }
        if(l==Letter::E){
            bottomAvailable=false;
        }
    }
    
    void changeAvailabilityNumber(Number n){
        if(n==Number::one){
            leftAvailable=false;
        }
        if(n==Number::five){
            rightAvailable=false;
        }
    }
    
    void resetAvailability(){
        topAvailable=true;
        bottomAvailable=true;
        leftAvailable=true;
        rightAvailable=true;
    }
};

#endif /* Card_hpp */
