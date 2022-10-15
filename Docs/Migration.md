# Migration

If your project already has GUI code, here are some tips to make migration painless:

## Win32

* Extract maxGUI events from the window procedure's message handlers. If you don't do this, you will likely find the message handler is no longer triggered. For example:

```case WM_CLOSE:
	PostQuitMessage(0);
	return 0;```

should become

```void MyForm::OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
	maxGUI::PostExitMessage(0);
}```

Here is a table of Win32 message types and their respective maxGUI events:

|WM_*                 |maxGUI event          |
|:--------------------|:---------------------|
|WM_CREATE            |OnCreated             |
|WM_CLOSE & WM_DESTROY|OnClosed              |
|WM_SIZE              |OnResized             |

* Any extra WM_s can all be handled inside the escape hatch, MyForm::OnWindowMessage().