import Button from "./Button";

function Message() {
  return (
    <div className="flex flex-col items-center justify-center h-screen bg-blue-500">
      <h2 className="text-3xl font-semibold mb-4">Login Page</h2>
      <form className="flex flex-col items-center bg-white p-8 rounded-lg shadow-md">
        <label className="mb-2">
          Username:
          <input
            type="text"
            className="border border-gray-400 rounded-md px-3 py-1 focus:outline-none focus:border-blue-500"
          />
        </label>
        <label className="mb-2">
          Password:
          <input
            type="password"
            className="border border-gray-400 rounded-md px-3 py-1 focus:outline-none focus:border-blue-500"
          />
        </label>
        <Button
          color="danger"
          onClick={() => "submit"}
          className="bg-red-500 hover:bg-red-600 text-white font-semibold py-2 px-4 rounded-md mt-4 focus:outline-none focus:ring-2 focus:ring-red-500"
        >
          Login
        </Button>
      </form>
    </div>
  );
}

export default Message;
