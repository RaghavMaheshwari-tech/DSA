class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>country;
    unordered_map<string,int>food_rating;
    unordered_map<string,string>food_country;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();

        for(int i=0;i<n;i++){
            food_rating[foods[i]]=ratings[i];
            food_country[foods[i]] = cuisines[i];

            country[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rating = food_rating[food];
        string countryy = food_country[food];

        food_rating[food] = newRating;

        auto &s = country[countryy];

        s.erase({-old_rating,food});
        s.insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto &s = country[cuisine];

        return s.begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */