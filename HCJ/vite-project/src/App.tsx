
import { Outlet } from "react-router-dom";

//import Alert from "./component/Alert"
import Navbar from "./component/Navbar"

const App = () => {
  return (
    <div className="flex flex-col items-center justify-top h-screen bg-orange-300">
    <div className="w-full p-6">
    <Navbar></Navbar>
        <Outlet></Outlet>
      </div>
      </div>
      
  )
}

export default App;