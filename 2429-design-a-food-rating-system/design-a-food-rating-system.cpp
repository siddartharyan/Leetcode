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
    unordered_map<string,string>foodMap;
    unordered_map<string,int>cuisineMap;
    unordered_map<string,priority_queue<Food>>cuisinesToFoodMap;  
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();++i){
            foodMap[foods[i]]=cuisines[i];
            cuisineMap[foods[i]]=ratings[i];
            cuisinesToFoodMap[cuisines[i]].push(Food(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisine = foodMap[food];
        cuisineMap[food]=newRating;
        cuisinesToFoodMap[cuisine].push(Food(newRating,food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated = cuisinesToFoodMap[cuisine].top();
        while(cuisineMap[highestRated.food] != cuisinesToFoodMap[cuisine].top().rating){
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