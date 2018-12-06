//
//  Board.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include "Utils.hpp"
#include "Card.hpp"
#include "Reward.hpp"
#include "CardDeck.hpp"
#include "RewardDeck.hpp"

static CardDeck* gameCdeck = &(CardDeck::make_CardDeck());
static RewardDeck* rDeck = &(RewardDeck::make_CardDeck());
class Board{
public:
    bool isFaceUp( const Letter&, const Number&);
    bool turnFaceUp( const Letter&, const Number&);
    bool turnFaceDown( const Letter&, const Number&);
    void reset();
    
    Card* getCard(const Letter& l, const Number& num){
        try{
            return gameCdeck->getByPosition((int)l*5+(int)num);
        }
        catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
            return nullptr;
        }
    }
    
    void setCard( const Letter&, const Number&, Card* ){
        
    }
    
    friend std::ostream& operator<<(std::ostream& os,Board & b) {
         os<<"================================\n";
        if(!gameCdeck->isEmpty()){
        for(int row = 0;row < gameCdeck->getByPosition(0)->getNRows();row++){
            (row==1)?(os <<"A"):(os <<" ");
            for(int col = 0; col < 5; col++){
                os <<(*gameCdeck->getByPosition(col))(row);
            }
            os <<"\n";
        }
        os <<"\n";
        for(int row1 = 0;row1 < gameCdeck->getByPosition(0)->getNRows();row1++){
            (row1==1)?(os <<"B"):(os <<" ");
            for(int col1 = 0; col1 < 5; col1++){
                os <<(*gameCdeck->getByPosition(col1+5))(row1);
            }
            os <<"\n";
        }
        os <<"\n";
        for(int row2 = 0;row2 < gameCdeck->getByPosition(0)->getNRows();row2++){
            (row2==1)?(os <<"C"):(os <<" ");
            for(int col2 = 0; col2 < 5; col2++){
                if(col2 == 2){
                    os<<"    ";
                }
                else{
                    os <<(*gameCdeck->getByPosition(col2+10))(row2);
                }
            }
            os <<"\n";
        }
        os <<"\n";
        for(int row3 = 0;row3 < gameCdeck->getByPosition(0)->getNRows();row3++){
            (row3==1)?(os <<"D"):(os <<" ");
            for(int col3 = 0; col3 < 5; col3++){
                os <<(*gameCdeck->getByPosition(col3+15))(row3);
            }
           os <<"\n";
        }
        os <<"\n";
        
        for(int row4 = 0;row4 < gameCdeck->getByPosition(0)->getNRows();row4++){
            (row4==1)?(os <<"E"):(os <<" ");
            for(int col4 = 0; col4 < 5; col4++){
                os <<(*gameCdeck->getByPosition(col4+20))(row4);
            }
            os <<"\n";
        }
        os <<"\n";
        os <<"   1   2   3   4   5\n";
        }
        else{
            os <<"deck empty\n";
        }
        os<<"-------------------------------\n";   
        return os;
    }
};

#endif /* Board_hpp */
