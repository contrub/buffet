# Course Project: Buffet System

## Overview

This project is a course assignment for the subject "Programming (Object-Oriented Technologies and Languages)." It implements a class hierarchy system to simulate customer service in a buffet environment.

## Features

- Display of available menu items.
- Order placement and management.
- Dynamic object-oriented structure using inheritance and polymorphism.
- Basic user interaction via the console.

## Technologies Used

- C++
- Standard Template Library (STL)
- Object-Oriented Programming (OOP) principles

## How to Run

1. Clone the repository.

2. Create a build directory and navigate into it:
```bash
mkdir build
cd build
```

3. Run CMake to generate the build files:
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

5. Prepare the menu CSV file with the following format before running the program.

<details> <summary>Click to expand CSV file format description</summary>
Each line in the CSV file should have 5 comma-separated fields: DishType,Title,Price,Weight,AdditionalField
- DishType: one of Cake, Coffee, Cola, Pizza, Salad, Tea
- Title: the dish name (string)
- Price: price as a decimal number
- Weight: weight as a decimal number

AdditionalField:

For Cake and Tea: a descriptive string (e.g., flavor, type)

For Coffee, Cola, Pizza, Salad: a numeric value (e.g., caffeine amount, calories)

Example:

```mathematica
Cake,Chocolate Cake,4.5,150,Chocolate
Coffee,Espresso,2.0,50,80
Cola,Coca-Cola,1.5,330,120
Pizza,Margherita,7.0,300,250
Salad,Greek Salad,5.0,200,150
Tea,Green Tea,1.8,250,Jasmine
```
</details>

6. Run the executable:
```bash
./buffet
```
