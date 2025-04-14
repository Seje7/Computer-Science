
import Button from "./Button";

function Passwords(){
  return (
    <div>
      <h2>CREDIENTIAL PAGE</h2>
      {/* Form for Signing in */}
      <form>
        <label>
          FirstName: <input type="text" />
        </label>
       <br />
       <label>
          LastName: <input type="text" />
        </label>
       <br />
       <label>
          Age: <input type="text" />
        </label>
       <br />
        <label>
          Password: <input type="password" />
        </label>
     <br />
     <Button color ="success" onClick={() => "submit"}>Sign UP</Button>
          </form>
    </div>
  );
}

export default Passwords;