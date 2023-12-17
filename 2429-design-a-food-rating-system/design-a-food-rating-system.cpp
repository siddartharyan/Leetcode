class Food{
    public:
        int rating;
        string food;
        Food(int rating,string food){
            this->rating=rating;
            this->food = food;
        }
        bool operator<(const Food &other) const{
        if(rating == other.rating){
            return food > other.food;
        }
        return rating < other.rating;
    }
};


class FoodRatings {
public:
    unordered_map<string,pair<string,int>>mp1;
    unordered_map<string,priority_queue<Food>>cuisinesToFoodMap;  
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();++i){
            mp1[foods[i]]=make_pair(cuisines[i],ratings[i]);
            cuisinesToFoodMap[cuisines[i]].push(Food(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto x = mp1[food];
        x.second = newRating;
        mp1[food]=x;
        cuisinesToFoodMap[x.first].push(Food(newRating,food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated = cuisinesToFoodMap[cuisine].top();
        while(mp1[highestRated.food].second != cuisinesToFoodMap[cuisine].top().rating){
            cuisinesToFoodMap[cuisine].pop();
            highestRated = cuisinesToFoodMap[cuisine].top();
        }
        return highestRated.food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */