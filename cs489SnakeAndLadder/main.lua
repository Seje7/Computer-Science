-- Authors: OSELUINOSEN EHI-DOUGLAS

local Globals = require "src.Globals"
local Push = require "libs.push"
local Background = require "src.games.Background"
local Boarding = require "src.games.Boarding"
local Die = require "src.games.Die"
local Stats = require "src.games.Stats"
local Object = require "src.games.Object"
local Board = require "src.games.Board"

local tileSize = 96
local statFont = love.graphics.newFont(26)


-- Load is executed only once; used to setup initial resource for your game
function love.load()
    love.window.setTitle("CS489 Jewels")
    Push:setupScreen(gameWidth, gameHeight, windowWidth, windowHeight, { fullscreen = false, resizable = true })
    math.randomseed(os.time()) -- RNG setup for later
    bg1 = Background("graphics/bg/back.png", 30)

    boarding = Boarding(50, 50, 400, 400)

    titleFont = love.graphics.newFont(32)

    stats = Stats()
    die = Die(480, 300)

    object = Object(50, 50, 140, 260)

    
end

-- When the game window resizes
function love.resize(w, h)
    Push:resize(w, h) -- must called Push to maintain game resolution
end

-- Event for keyboard pressing
function love.keypressed(key)
    if key == "escape" then
        love.event.quit()
    elseif key == "F2" or key == "tab" then
        debugFlag = not debugFlag
    elseif key == "return" and gameState == "start" then
        gameState = "play"
    elseif key == "return" and gameState == "over" then
        gameState = "play"
    elseif key == "space" and gameState == "play" then
            die:roll()
            stats:Recording()
    end
end

-- Event to handle mouse pressed (there is another for mouse release)
function love.mousepressed(x, y, button, istouch)
    local gx, gy = Push:toGame(x, y)
    if button == 1 then -- regurlar mouse click
        -- board:mousepressed(gx, gy)
    elseif debugFlag then
        if button == 2 and love.keyboard.isDown("lctrl", "rctrl") then
           -- testexp:trigger(gx, gy)
        elseif button == 2 then
            --board:cheatGem(gx, gy)
        end
    end
end

-- Update is executed each frame, dt is delta time (a fraction of a sec)
function love.update(dt)
    bg1:update(dt)
    stats:update(dt)

    if gameState == "start" then
     
    elseif gameState == "play" then
      die:update(dt)
      if stats.dieRecording >= stats.MAX_BOARD_ROWS then
        gameState = "over"

      end
   
    elseif gameState == "over" then
       
    end
end

-- Draws the game after the update
function love.draw()
    Push:start()

    -- always draw between Push:start() and Push:finish()
    if gameState == "start" then
        drawStartState()
    elseif gameState == "play" then
        drawPlayState()
    elseif gameState == "over" then
        drawGameOverState()
    end

    if debugFlag then
        love.graphics.print("DEBUG ON", 20, gameHeight - 20)
    end

    Push:finish()
end

function drawStartState()
    bg1:draw()

    love.graphics.printf("SNAKE AND LADDERS", titleFont, 0, 50,
    gameWidth, "center")
love.graphics.printf("Press Enter to Play or Escape to exit",
    0, 90, gameWidth, "center")
end

function drawPlayState()
    bg1:draw()
    boarding:draw()
    object:draw()
    die:draw()
    stats:draw()

    local x, y = boarding:tileToPosition(1, tileSize)
   -- love.graphics.printf("Tile"..1, "at:", x, y)
    love.graphics.printf("Score "..tostring(1).."/"..tostring(x).."/"..tostring(y), statFont ,200,10,200)

   
   
end

function drawGameOverState()
   -- value = stats.totalScore
    love.graphics.printf("GameOver", titleFont, 0, 50,
        gameWidth, "center")
    love.graphics.printf("Press Enter to Play or Escape to exit",
        0, 90, gameWidth, "center")
   -- love.graphics.printf("FINAL SCORE: " .. value,
     --   0, 120, gameWidth, "center")
end
-- * git this 