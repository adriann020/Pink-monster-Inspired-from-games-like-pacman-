
#pragma once

class  Score {

  private:

    int score = 0;

  public:

   int reset(){
     score = 0;
     return score;
   }

   void forScore() {
        score++;
    }
   int getScore() const {
        return score;
    }
    
  
}; 
