##This program creates a class for rectangle with methods to calculate it's area and perimeter
##It also calculates the sum of area and perimeter. The data members are private.
##User will input the length and height in main() and the program allows the user to
##change the length of the object that was instantiated.

#The program shows docstrings and typehints.


class Rectangle:
    # Construct a rectangle object - note if default args are used no need to typehint eg def __init__(self, length = 1.0, height = 1.0):
    def __init__(self, length: float, height: float):
        self.__length = length
        self.__height = height
        
    #there are two data members, therefore we have 2 getters
    def getLength(self) -> float:
        return self.__length

    def getHeight(self) -> float:
        return self.__height

    #there are two data members, therefore we have 2 setters
    def setLength(self, length: float) -> None:
        self.__length = length

    def setHeight(self, height: float) -> None:
        self.__length = length

	#below are the three methods for the class rectangle
    def getPerimeter(self) -> float:
        """Method calculates the perimeter of rectangle"""
        return 2 * (self.__length + self.__height) 

    def getArea(self) -> float:
        """Method calculates the area of rectangle"""
        return self.__length * self.__height

    def getSumAreaPerimeter(self) -> float:
        """

        Method calcs the sum of rectangle perimeter and area
        Note how the methods getPerimeter() and getArea() are
        called in here

        """
        return self.getPerimeter() + self.getArea()   
        
      
def main():
    #user input for length and height
    length = float(input("Enter a length "))
    height = float(input("Enter a height "))
                         
    # Create a rectangle1 with length and height from user input
    rectangle1 = Rectangle(length, height)
    print("The area of the rectangle of length", rectangle1.getLength(), "and height", rectangle1.getHeight(), "is", rectangle1.getArea())
    print("The perimeter of the rectangle is", rectangle1.getPerimeter())

    #calls the getSumAreaPerimeter method and prints the result
    print("The sum of the area and perimeter is", rectangle1.getSumAreaPerimeter())                  
    print()
    
    #loop to change length and set new length for object     
    changeL=input("Do you want to change the radius? y for yes or enter to quit ")
    while changeL == 'y':
        # Modify the private radius data member through the setter method setRadius
        print()

        #user inputs a new radius with the same object circle1
        length = float(input("Type in a new length "))
                     
        print("The length of rectangle before using setter to change is", rectangle1.getLength())


    
        #Private data member can only be access via a mutator method- setLength()
        #change the original length to the new radius using the set method
        rectangle1.setLength(length)
        print("The length of the rectangle after using setter to change the length", rectangle1.getLength())
        print("The area of the rectangle of length", rectangle1.getLength(), "after using setter to change is", rectangle1.getArea())
        print("The perimeter of the rectangle", rectangle1.getPerimeter())
        
        #calls the getSumAreaPerimeter method and prints the result
        print("The sum of the area and perimeter is", rectangle1.getSumAreaPerimeter())
        print()
        
        changeL = input("Do you want to change the length? y for yes or enter to quit ")
    

    
if __name__ == "__main__":
    main() 
