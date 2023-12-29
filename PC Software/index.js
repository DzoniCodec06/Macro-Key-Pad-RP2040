const { app, BrowserWindow } = require("electron");
//const path = require("path");
const createWindow = () => {
    const win = new BrowserWindow({
        resizable: true,
        //autoHideMenuBar: true,
        webPreferences: {
            nodeIntegration: true,
            contextIsolation: false,
            devTools: true,
            //preload: path.join(__dirname, "preload.js")
        }
    });

    win.loadFile("./src/index.html"); 
    win.webContents.openDevTools();
    win.setMenuBarVisibility(false);
    win.maximize();
}

app.whenReady().then(() => {
    createWindow();

    app.on("activate", () => {
        if (BrowserWindow.getAllWindows().length === 0) createWindow();
    });
})

app.on("window-all-closed", () => {
    if (process.platform != "darwin") app.quit();
});
