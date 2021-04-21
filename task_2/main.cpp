/**
 * This program rotates the matrix by 90 degrees clockwise. 
 * For this task, you are not allowed to use a predefined 
 * function that does that under the hood (for example, np.transpose).
 * 
 * @author Magzhan Kairanbay
 * 
 * @version 1.0.0
 */
#include <iostream>
#include <vector>

using namespace std;

/** This function reads the elements of nxm matrix
 * and returns initialized matrix
 * 
 * @param number of rows
 * @param number of columns
 * 
 * @return initialized 2d matrix
 */
vector<vector<int>> readElements(int n, int m) {
    
    // initialize an empty 2d image
    vector<vector<int>> image;
    
    // iterate through the each row of matrix
    for (int i = 0; i < n; i++) {
        // empty row
        vector<int> tempRow;
        // iterate through the each column of the matrix
        for (int j = 0; j < m; j++) {
            // read each element and add it to the temporary vector
            int element;
            cin >> element;
            tempRow.push_back(element);
        }
        // add row to the image
        image.push_back(tempRow);
    }
    
    return image;
}

/**
 * This function checks whether the image is not empty
 * 
 * @param input image
 * 
 * @return true if image contains at least one element, otherwise returns false
 */
bool validateImageSize(vector<vector<int>> image) {
    // suppose image contains at least one row
    if (image.size() > 0) {
        // suppose image contains at least one row
        if (image[0].size() > 0) {
            return true;
        }   
        return false;
    }
    return false;
}

/** This function rotates the matrix by 90 degrees clockwise
 * 
 * @param input 2d matrix
 * 
 * @return rotated by 90 degree 2d matrix
 */
vector<vector<int>> rotateAnImage(vector<vector<int>> image) {

    // create new transposed 2d image
    vector<vector<int>> rotatedImage;

    // make sure that image is not empty
    if (validateImageSize(image)) {
        // number of rows and number of columns
        int n = image.size();
        int m = image[0].size();
        
        // if n == m then do rotation in place
        if (n == m) {
            // traverse through the each cycle
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    // Swap elements in clockwise direction
                    int temp = image[i][j];
                    image[i][j] = image[n - 1 - j][i];
                    image[n - 1 - j][i] = image[n - 1 - i][n - 1 - j];
                    image[n - 1 - i][n - 1 - j] = image[j][n - 1 - i];
                    image[j][n - 1 - i] = temp;
                }
            }
            return image;
        } else {
            
            // iterate through the each column
            for (int j = 0; j < m; j++) {
                // empty row
                vector<int> tempRow;
                // iterate through the each row
                for (int i = n - 1; i >= 0; i--) {
                    tempRow.push_back(image[i][j]);
                }
                // add row to the rotated image
                rotatedImage.push_back(tempRow);
            }
        }
    }
    
    return rotatedImage;
}

/**
 * This function prints the elements of the image
 * 
 * @param input image
 */
void printAnImage(vector<vector<int>> image) {
    
    // make sure that image contains at least one element
    if (validateImageSize(image)) {
        // number of rows and number of columns
        int n = image.size();
        int m = image[0].size();  
        
        cout << "90 degree rotated matrix is: " << endl;
        
        // iterate through the each row
        for (int i = 0; i < n; i++) {
            // iterate through the each column
            for (int j = 0; j < m; j++) {
                cout << image[i][j];
                if (j != m - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
}

int main()
{
    
    // initialize and read number of rows and columns
    int n, m;
    cin >> n >> m;
    
    // initialize nxm image with given elements
    vector<vector<int>> image = readElements(n, m);
    
    // make sure that image contains at least one element
    if (validateImageSize(image)) {
        // rotate image to 90 degrees
        vector<vector<int>> rotatedImage = rotateAnImage(image); 
        printAnImage(rotatedImage);
    }

    return 0;
}
