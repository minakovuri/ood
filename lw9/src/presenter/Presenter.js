class Presenter {
    constructor(view) {
        this._view = view

        this._initView()
    }

    _initView() {
        const menuView = this._view.getMenu()

        menuView.doOnAddTriangle(() => console.log('Add triangle'))
        menuView.doOnAddRectangle(() => console.log('Add rectangle'))
        menuView.doOnAddEllipse(() => console.log('Add ellipse'))
    }
}

export {
    Presenter,
}