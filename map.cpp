// map.cpp
#include "map.h"

Map::Map() : mapData(SCREEN_HEIGHT / TILE_HEIGHT, std::vector<char>(SCREEN_WIDTH / TILE_WIDTH)) {
    // Initialize member variables
    tileSurface = nullptr;
    tileTexture = nullptr;
    
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        return;
    }
}


void Map::setColoredTile(char c,SDL_Event& event){
        int x=event.button.x;
        int y=event.button.y;
        // Calculate tile position
        int tileX = x / TILE_HEIGHT;
        int tileY = y / TILE_WIDTH;

        if(tileX>=0 && tileX<mapData[0].size() && tileY>=0 && tileY<mapData.size()){        
            mapData[tileY][tileX]=c;
        }
}

void Map::saveMap(const std::string& filename){

    std::ofstream outFile(filename);

    if(!outFile.is_open()){
        std::cerr << "failed to open a file \n";
        return;
    }

    for (auto row:mapData){
        for (auto tile:row){
            outFile << tile;
        }
        outFile << '\n';
    }
    outFile.close();
    std::cout << "Map saved to " << filename << std::endl;
}

void Map::loadMap(const std::string& filename){
    std::ifstream inFile(filename);

    if(!inFile.is_open()){
        std::cerr << "failed to open a file \n";
    }
    
    // clearing the current map
    mapData.clear(); 
    std::string Line;
    while(std::getline(inFile, Line)){
        std::vector<char> row;
        for (char c : Line) {
            row.emplace_back(c);
        }
        mapData.emplace_back(row);
    }
    inFile.close();
    std::cout << "Map loaded from " << filename << std::endl;        

}


void Map::handleTileMapEvent( SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.clicks == 1) {
            setColoredTile('y', event);
    
        } else if (event.button.clicks == 2) {
            setColoredTile('r', event);
        } else if (event.button.clicks == 3) {
            setColoredTile('b', event);
        }
    }
}


void Map::displayTiles() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    for (int i = 0; i < mapData.size(); i++) {
    for (int j = 0; j < mapData[0].size(); j++) {
        SDL_Rect rect = {j * TILE_WIDTH, i * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT};

        switch (mapData[i][j]) {
            case 'y': // Yellow
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                break;
            case 'r': // Red
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                break;
            case 'b': // Blue
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                break;
            default:  // Default background color (e.g., black)
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                break;
        }

        // Render the rectangle
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

Map::~Map() {
    if (tileTexture) {
        SDL_DestroyTexture(tileTexture);
        tileTexture = nullptr;
    }
    IMG_Quit();  
}




