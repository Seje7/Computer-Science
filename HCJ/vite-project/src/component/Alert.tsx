
interface  Props{
    children: string;
    onClose: ()=> void
}

const Alert = ({children, onClose}: Props) => {
  return (
    <div className="alert alert-primary alert-dissmisible"> {children}
    <button type="button" className="btn-close" onClick={onClose}
    data-bs-dismiss="alert" aria-label="Close"></button>
    </div>
  )
}

export default Alert