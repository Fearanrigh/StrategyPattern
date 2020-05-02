//
//  main.cpp
//  Strategy
//
//  Created by Sean Barton on 2020-05-01.
//  Copyright © 2020 Fearanrigh. All rights reserved.
//

#include <iostream>

using namespace std;

class StrategyInterface
{
    public:
        virtual void execute() const = 0;
};

class ConcreteStrategyA: public StrategyInterface
{
    public:
        void execute() const override {
            cout << "Called ConcreteStrategyA execute method" << endl;
        }
};

class ConcreteStrategyB: public StrategyInterface
{
    public:
        void execute() const override {
            cout << "Called ConcreteStrategyB execute method" << endl;
        }
};

class ConcreteStrategyC: public StrategyInterface
{
    public:
        void execute() const override {
            cout << "Called ConcreteStrategyC execute method" << endl;
        }
};

class Context
{
    private:
        StrategyInterface * strategy_;

    public:
        explicit Context(StrategyInterface *strategy):strategy_(strategy) {}

        void set_strategy(StrategyInterface *strategy) {
            strategy_ = strategy;
        }

        void execute() const {
            strategy_->execute();
        }
};

int main(int argc, char *argv[]) {
    ConcreteStrategyA concreteStrategyA;
    ConcreteStrategyB concreteStrategyB;
    ConcreteStrategyC concreteStrategyC;

    Context context(&concreteStrategyA);

    context.execute(); // output: "Called ConcreteStrategyA execute method"
    
    context.set_strategy(&concreteStrategyB);
    context.execute(); // output: "Called ConcreteStrategyB execute method"
    
    context.set_strategy(&concreteStrategyC);
    context.execute(); // output: "Called ConcreteStrategyC execute method"

    return 0;
}
